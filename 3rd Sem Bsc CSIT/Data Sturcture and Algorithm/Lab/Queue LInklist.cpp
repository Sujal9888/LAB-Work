#include<iostream>
using namespace std;

struct queue {
    int info;
    queue* next;
};

// Check if queue is empty
bool checkEmptyQueue(queue* rear, queue* front) {
    return (rear == NULL && front == NULL);
}

// Enqueue element
void enQueue(queue* &rear, queue* &front, int data) {
    queue* newNode = new queue;
    newNode->info = data;
    newNode->next = NULL;

    if(rear == NULL && front == NULL) { // Empty queue
        front = newNode;
        rear = newNode;
        cout << data << " enqueued" << endl;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    cout << data << " enqueued" << endl;
}

// Dequeue element
void deQueue(queue* &rear, queue* &front) {
    if(checkEmptyQueue(rear, front)) {
        cout << "Queue is Empty" << endl;
        return;
    }

    queue* temp = front;
    cout << temp->info << " dequeued" << endl;

    if(front == rear) { // Only one element
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }

    delete temp;
}

// Traverse queue
void traverse(queue* front) {
    if(front == NULL) {
        cout << "Queue is Empty" << endl;
        return;
    }

    queue* temp = front;
    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    queue* rear = NULL;
    queue* front = NULL;
    int key, data;

    do {
        cout << "\n------Queue (Linked List)------" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Traverse\n4. Check Empty\n5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> key;

        switch(key) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                enQueue(rear, front, data);
                break;
            case 2:
                deQueue(rear, front);
                break;
            case 3:
                traverse(front);
                break;
            case 4:
                if(checkEmptyQueue(rear, front))
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
        }
    } while(key != 5);

    return 0;
}
