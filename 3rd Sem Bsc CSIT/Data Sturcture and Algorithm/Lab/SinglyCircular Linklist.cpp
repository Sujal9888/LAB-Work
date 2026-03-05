#include<iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

// Insert at the beginning
void insertBeginning(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->info = data;
    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at the end
void insertEnd(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->info = data;
    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert at a specific position
void insertSpecificPoint(Node* &head, int data, int pos) {
    Node* newNode = new Node;
    newNode->info = data;

    if(pos < 1) {
        cout << "Invalid Position" << endl;
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertBeginning(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if(count != pos-1) {
        cout << "Invalid Position" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }
    Node* temp = head;
    if(head->next == head) {
        cout << head->info << " deleted" << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* last = head;
    while(last->next != head) last = last->next;
    head = head->next;
    last->next = head;
    cout << temp->info << " deleted" << endl;
    delete temp;
}

// Delete from end
void deleteEnd(Node* &head) {
    if(head == NULL) {
        cout << "Error: Empty List" << endl;
        return;
    }
    if(head->next == head) {
        cout << head->info << " deleted" << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != head) temp = temp->next;
    cout << temp->next->info << " deleted" << endl;
    delete temp->next;
    temp->next = head;
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
    int count = 1;
    while(count < pos-1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if(temp->next == head || count != pos-1) {
        cout << "Invalid Position" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    cout << del->info << " deleted" << endl;
    delete del;
}

// Traverse the list
void singlyTraverse(Node* head) {
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
        cout << "\n-----Singly Circular Linked List----" << endl;
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
                singlyTraverse(head);
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
