#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Dynamically allocate adjacency matrix
    int** graph = new int*[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    // Use a large number to simulate infinity
    const int INF = 1e9;

    // Dynamically allocate distance and visited arrays
    int* dist = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Output results
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << dist[i] << "\n";

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] dist;
    delete[] visited;

    return 0;
}
