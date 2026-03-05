#include<iostream>
using namespace std;

struct Node {
    int info;
    Node* prev;
    Node* next;
};

// Insert at beginning
void insertBeginning(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insertEnd(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position
void insertSpecificPoint(Node* &head, int data, int pos) {
    if(pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    if(pos == 1) {
        insertBeginning(head, data);
        return;
    }

    Node* temp = head;
    int i = 1;
    while(temp != NULL && i < pos-1) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->info = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    cout << temp->info << " deleted" << endl;
    delete temp;
}

// Delete from end
void deleteEnd(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }

    Node* temp = head;
    if(temp->next == NULL) { // Only one node
        cout << temp->info << " deleted" << endl;
        delete temp;
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    cout << temp->info << " deleted" << endl;
    temp->prev->next = NULL;
    delete temp;
}

// Delete from a specific position
void deleteSpecificPoint(Node* &head, int pos) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }

    if(pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    if(pos == 1) {
        deleteBeginning(head);
        return;
    }

    Node* temp = head;
    int i = 1;
    while(temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    cout << temp->info << " deleted" << endl;
    delete temp;
}

// Traverse the list
void doublyTraverse(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu
int main() {
    Node* head = NULL;
    int choice, data, pos;

    do {
        cout << "\n-----Doubly Linked List----" << endl;
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Specific Point\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Specific Point\n";
        cout << "7. Traverse\n8. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Data to Store at Beginning: ";
                cin >> data;
                insertBeginning(head, data);
                break;
            case 2:
                cout << "Enter Data to Store at End: ";
                cin >> data;
                insertEnd(head, data);
                break;
            case 3:
                cout << "Enter Position and Data to Store: ";
                cin >> pos >> data;
                insertSpecificPoint(head, data, pos);
                break;
            case 4:
                deleteBeginning(head);
                break;
            case 5:
                deleteEnd(head);
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                deleteSpecificPoint(head, pos);
                break;
            case 7:
                doublyTraverse(head);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;  
        }
    } while(choice != 8);

    return 0;
}
