#include<iostream>
using namespace std;

// Define node for stack
struct StackNode {
    int info;
    StackNode* next;
};

// Check if stack is empty
bool checkEmpty(StackNode* top) {
    return (top == NULL);
}

// Push element
void push(StackNode* &top, int data) {
    StackNode* newNode = new StackNode;
    newNode->info = data;
    newNode->next = top;
    top = newNode;
    cout << data << " pushed" << endl;
}

// Pop element
void pop(StackNode* &top) {
    if(checkEmpty(top)) {
        cout << "Stack is Empty" << endl;
        return;
    }

    StackNode* temp = top;
    top = top->next;
    cout << temp->info << " popped" << endl;
    delete temp;
}

// Traverse stack
void traverse(StackNode* top) {
    if(checkEmpty(top)) {
        cout << "Stack is Empty" << endl;
        return;
    }

    StackNode* temp = top;
    cout << "Stack elements: ";
    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    StackNode* top = NULL;
    int choice, data;

    do {
        cout << "\n----- Stack (Linked List) -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check Empty" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter data to Push: ";
                cin >> data;
                push(top, data);
                break;

            case 2:
                pop(top);
                break;

            case 3:
                if(checkEmpty(top))
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;

            case 4:
                traverse(top);
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 5." << endl;
        }

    } while(choice != 5);

    return 0;
}

