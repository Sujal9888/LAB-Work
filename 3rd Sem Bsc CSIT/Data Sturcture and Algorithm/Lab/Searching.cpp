#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value){
    if(root == NULL){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

Node* searchBST(Node* root, int key){
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

int main() {
    int arr[100], n, key, choice;
    int low, high, mid, i;
    int found;

    Node* root = NULL;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++){
        cin >> arr[i];
        root = insert(root, arr[i]); // insert into BST
    }

    do {
        cout << "\n--- Searching Menu ---\n";
        cout << "1. Sequential / Linear Search\n";
        cout << "2. Binary Search (Array)\n";
        cout << "3. Binary Search Tree (Linked List)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

        case 1:
            cout << "Enter element to search: ";
            cin >> key;
            found = 0;

            for(i = 0; i < n; i++){
                if(arr[i] == key){
                    cout << "Element found at position " << i + 1 << endl;
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                cout << "Element not found\n";
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> key;

            low = 0;
            high = n - 1;
            found = 0;

            while(low <= high){
                mid = (low + high) / 2;

                if(arr[mid] == key){
                    cout << "Element found at position " << mid + 1 << endl;
                    found = 1;
                    break;
                }
                else if(arr[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            if(found == 0)
                cout << "Element not found\n";
            break;

        case 3:
            cout << "Enter element to search in BST: ";
            cin >> key;

            if(searchBST(root, key) != NULL)
                cout << "Element found in BST\n";
            else
                cout << "Element not found in BST\n";
            break;

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
