#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ----------- Kruskal's Algorithm ----------- */
struct Edge {
    int u, v, weight;
};

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int u, int v) {
    parent[findParent(parent, u)] = findParent(parent, v);
}

void Kruskal(vector<Edge> edges, int n) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.weight < b.weight; });
    int parent[n];
    for(int i = 0; i < n; i++) parent[i] = i;

    cout << "\nKruskal's MST edges:\n";
    int total = 0;
    for(auto e : edges){
        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);
        if(u != v){
            cout << e.u << " - " << e.v << " : " << e.weight << "\n";
            total += e.weight;
            unionSets(parent, u, v);
        }
    }
    cout << "Total weight of MST: " << total << "\n";
}

/* ----------- Prim's Algorithm ----------- */
void Prim(int graph[10][10], int n) {
    int key[10], parent[10];
    bool mstSet[10] = {false};

    for(int i = 0; i < n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for(int count = 0; count < n - 1; count++){
        int u = -1, minKey = INT_MAX;
        for(int i = 0; i < n; i++){
            if(!mstSet[i] && key[i] < minKey){
                minKey = key[i];
                u = i;
            }
        }

        if(u == -1) break; // disconnected graph
        mstSet[u] = true;

        for(int v = 0; v < n; v++){
            if(graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nPrim's MST edges:\n";
    int total = 0;
    for(int i = 1; i < n; i++){
        if(parent[i] != -1){
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
            total += graph[i][parent[i]];
        }
    }
    cout << "Total weight of MST: " << total << "\n";
}

/* ----------- Main Menu ----------- */
int main(){
    int choice, n;
    int graph[10][10];
    vector<Edge> edges;

    cout << "Enter number of vertices (max 10): ";
    cin >> n;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(i < j && graph[i][j] != 0){
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    do{
        cout << "\n--- MST Menu ---\n";
        cout << "1. Kruskal's Algorithm\n";
        cout << "2. Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                Kruskal(edges, n);
                break;
            case 2:
                Prim(graph, n);
                break;
            case 3:
                cout << "Program Ended\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}
