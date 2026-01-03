#include<iostream>
#define max 20
using namespace std;

class QADT{
    int rear, front, q[max];
public:
    QADT(){
        rear = -1;
        front = 0;
    }
    void MakeEmptyQueue(){
        rear = -1;
        front = 0;
        cout<<"\nQueue Emptied.\n";
    }
    bool IsFull(){
        return (rear == max - 1);
    }
    bool IsEmpty(){
        return (rear < front);
    }
    void Enqueue(int x){
        if(IsFull())
            cout << "\nQueue is full.\n";
        else{
            q[++rear] = x;
            cout << "\nData inserted.\n";
        }
    }
    void Dequeue(){
        if(IsEmpty())
            cout << "\nQueue is Empty.\n";
        else
            cout << "\nDeleted Data: " << q[front++] << endl;
    }
    void Traverse(){
        if(IsEmpty())
            cout << "\nQueue is Empty.\n";
        else{
            cout << "\nData of Queue: ";
            for(int i = front; i <= rear; i++)
                cout << q[i] << " ";
            cout << endl;
        }
    }
};

class CQ{
    int rear, front, q[max];
public:
    CQ(){
        rear = front = max - 1;
    }
    void MakeEmptyQueue(){
        rear = front = max - 1;
        cout<<"\nQueue Emptied.\n";
    }
    bool IsFull(){
        return (front == (rear + 1) % max);
    }
    bool IsEmpty(){
        return (rear == front);
    }
    void Enqueue(int x){
        if(IsFull())
            cout << "\nQueue is full.\n";
        else{
            rear = (rear + 1) % max;
            q[rear] = x;
            cout << "\nData inserted.\n";
        }
    }
    void Dequeue(){
        if(IsEmpty())
            cout << "\nQueue is Empty.\n";
        else{
            front = (front + 1) % max;
            cout << "\nDeleted Data: " << q[front] << endl;
        }
    }
    void Traverse(){
        if(IsEmpty())
            cout << "\nQueue is Empty.\n";
        else{
            cout << "\nData of Queue: ";
            for(int i = (front + 1) % max; i != (rear + 1) % max; i = (i + 1) % max)
                cout << q[i] << " ";
            cout << endl;
        }
    }
};

class PQ{
    int rear, front, q[max];
public:
    PQ(){
        rear = -1;
        front = 0;
    }
    void MakeEmptyQueue(){
        rear = -1;
        front = 0;
        cout<<"\nQueue Emptied.\n";
    }
    bool IsFull(){
        return (rear == max - 1);
    }
    bool IsEmpty(){
        return (rear < front);
    }
   void Enqueue(int x){
		if (IsFull()){
			cout<<"\nQueue is full.\n";
		}
		else{
			rear=rear+1;
			q[rear]=x;
			cout<<"\nData inserted.\n";
		}
	}
    void DequeueAscending(){
        if(IsEmpty()){
            cout << "\nQueue is Empty.\n";
            return;
        }
        int minIndex = front;
        for(int i = front + 1; i <= rear; i++)
            if(q[i] < q[minIndex])
                minIndex = i;
        cout << "\nDeleted Data: " << q[minIndex] << endl;
        for(int i = minIndex; i < rear; i++)
            q[i] = q[i + 1];
        rear--;
    }
    void DequeueDescending(){
        if(IsEmpty()){
            cout << "\nQueue is Empty.\n";
            return;
        }
        int maxIndex = front;
        for(int i = front + 1; i <= rear; i++)
            if(q[i] > q[maxIndex])
                maxIndex = i;
        cout << "\nDeleted Data: " << q[maxIndex] << endl;
        for(int i = maxIndex; i < rear; i++)
            q[i] = q[i + 1];
        rear--;
    }
    void Traverse(){
        if(IsEmpty())
            cout << "\nQueue is Empty.\n";
        else{
            cout << "\nData of Queue: ";
            for(int i = front; i <= rear; i++)
                cout << q[i] << " ";
            cout << endl;
        }
    }
};

int main(){
    QADT qu;
    CQ cq;
    PQ p;
    int n1, a;

    do{
    	cout<< "\n Choose from the following\n"
			<<"1. Linear Queue\n"
			<<"2. Circular Queue\n"
			<<"3. Priority Queue\n"
			<<"4. Exit\n";
		cout<<"Enter your Choice:";
        cin >> n1;
        int n;

        if(n1 == 1){
            do{
                cout <<"\n Linear Queue\n"
					<<"1. Make Empty\n"
					<<"2. Enqueue\n"
					<<"3. Dequeue\n"
					<<"4. Traverse\n"
					<<"5. Exit\n";
				cout<<"Enter Your Choice:";
                cin >> n;
                if(n == 1) qu.MakeEmptyQueue();
                else if(n == 2){ 
					cout<<"Enter data:";
					cin >> a; qu.Enqueue(a); 
				}
                else if(n == 3) qu.Dequeue();
                else if(n == 4) qu.Traverse();
            } while(n != 5);
        }
        else if(n1 == 2){
            do{
                cout <<"\n Circular Queue\n"
					<<"1. Make Empty\n"
					<<"2. Enqueue\n"
					<<"3. Dequeue\n" 
					<<"4. Traverse\n"
					<<"5. Exit\n";
				cout<<"Enter Your Choice:";
                cin >> n;
                if(n == 1) cq.MakeEmptyQueue();
                else if(n == 2){
				cout<<"Enter data:";
				 cin >> a; cq.Enqueue(a); 
				 }
                else if(n == 3) cq.Dequeue();
                else if(n == 4) cq.Traverse();
            } while(n != 5);
        }
        else if(n1 == 3){
            do{
                cout<<"\n Priority Queue\n"
				<<"1. Make Empty\n"
				<<"2. Enqueue\n"
				<<"3. Dequeue\n"
				<<"4. Traverse\n"
				<<"5. Exit\n";
				cout<<"Enter Your Choice:";
                cin >> n;
                if(n == 1) p.MakeEmptyQueue();
                else if(n == 2){
                	cout<<"Enter data:";
				 	cin >> a; 
					p.Enqueue(a); 
				}
                else if(n == 3){
                    int d;
                    cout<< "1.Descending\n"
						<<"2.Ascending\n";
					cout<<"Enter your choice:";
                    cin >> d;
                    if(d == 1) p.DequeueDescending();
                    else if(d == 2) p.DequeueAscending();
                }
                else if(n == 4) p.Traverse();
            } while(n != 5);
        }
    } while(n1 != 4);

    return 0;
}

