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

    if(head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->info = data;

    if(head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
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
    while(i < pos-1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if(i != pos-1) {
        cout << "Invalid Position" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->info = data;
    Node* nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;
}

// Delete from beginning
void deleteBeginning(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }

    Node* temp = head;
    if(head->next == head) { // Only one node
        cout << temp->info << " deleted" << endl;
        delete temp;
        head = NULL;
        return;
    }

    Node* last = head->prev;
    head = head->next;
    last->next = head;
    head->prev = last;

    cout << temp->info << " deleted" << endl;
    delete temp;
}

// Delete from end
void deleteEnd(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }

    Node* last = head->prev;

    if(last == head) { // Only one node
        cout << last->info << " deleted" << endl;
        delete last;
        head = NULL;
        return;
    }

    Node* secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;

    cout << last->info << " deleted" << endl;
    delete last;
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
    while(i < pos-1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    Node* del = temp->next;
    if(del == head) {
        cout << "Invalid Position" << endl;
        return;
    }

    Node* nextNode = del->next;
    temp->next = nextNode;
    nextNode->prev = temp;

    cout << del->info << " deleted" << endl;
    delete del;
}

// Traverse
void doublyTraverse(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, data, pos;

    do {
        cout << "\n-----Doubly Circular Linked List----" << endl;
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Specific Point\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Specific Point\n";
        cout << "7. Traverse\n8. Exit" << endl;
        cout << "Enter your Choice: ";
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
        }
    } while(choice != 8);

    return 0;
}
