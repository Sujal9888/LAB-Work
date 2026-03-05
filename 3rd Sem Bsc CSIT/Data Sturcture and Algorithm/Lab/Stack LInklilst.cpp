#include<iostream>
using namespace std;

struct stack {
    int info;
    stack* next;
};

// Check if stack is empty
bool checkEmpty(stack* top) {
    return top == NULL;
}

// Push element
void push(stack* &top, int data) {
    stack* newNode = new stack;
    newNode->info = data;
    newNode->next = top;
    top = newNode;
    cout << data << " pushed" << endl;
}

// Pop element
void pop(stack* &top) {
    if(checkEmpty(top)) {
        cout << "Empty Stack" << endl;
        return;
    }
    stack* temp = top;
    top = top->next;
    cout << temp->info << " popped" << endl;
    delete temp;
}

// Traverse stack
void traverse(stack* top) {
    if(checkEmpty(top)) {
        cout << "Stack is Empty" << endl;
        return;
    }
    stack* temp = top;
    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    stack* top = NULL;
    int choice, data;

    do {
        cout << "\n-----Stack (Linked List)-----" << endl;
        cout << "1. Push\n2. Pop\n3. Check Empty\n4. Traverse\n5. Exit" << endl;
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
        }
    } while(choice != 5);

    return 0;
}
