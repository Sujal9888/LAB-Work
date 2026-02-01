#include<iostream>
using namespace std;

struct Node{
	int info;
	Node* next;
};

void insertBeginning(Node* &head, int data){
	Node* newNode = new Node;
	newNode->info = data;
	newNode->next = head;
	head = newNode;
}

void insertEnd(Node* &head, int data){
	Node* newNode = new Node;
	newNode->info = data;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;
		return;
	}

	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertSpecificPoint(Node* &head, int data, int pos){
	if(pos < 1){
		cout<<"Invalid Position"<<endl;
		return;
	}

	Node* newNode = new Node;
	newNode->info = data;

	if(pos == 1){
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* temp = head;
	int i = 1;

	while(temp != NULL && i < pos-1){
		temp = temp->next;
		i++;
	}

	if(temp == NULL){
		cout<<"Invalid Position"<<endl;
		delete newNode;
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteBeginning(Node* &head){
	if(head == NULL){
		cout<<"Error: Empty List"<<endl;
		return;
	}

	Node* temp = head;
	head = head->next;
	cout<<temp->info<<" deleted"<<endl;
	delete temp;
}

void deleteEnd(Node* &head){
	if(head == NULL){
		cout<<"Error: Empty List"<<endl;
		return;
	}

	if(head->next == NULL){
		cout<<head->info<<" deleted"<<endl;
		delete head;
		head = NULL;
		return;
	}

	Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}

	cout<<temp->next->info<<" deleted"<<endl;
	delete temp->next;
	temp->next = NULL;
}

void deleteSpecificPoint(Node* &head, int pos){
	if(head == NULL){
		cout<<"Error: Empty List"<<endl;
		return;
	}

	if(pos < 1){
		cout<<"Invalid Position"<<endl;
		return;
	}

	if(pos == 1){
		Node* del = head;
		cout<<del->info<<" deleted"<<endl;
		head = head->next;
		delete del;
		return;
	}

	Node* temp = head;
	int i = 1;

	while(temp != NULL && i < pos-1){
		temp = temp->next;
		i++;
	}

	if(temp == NULL || temp->next == NULL){
		cout<<"Invalid Position"<<endl;
		return;
	}

	Node* del = temp->next;
	cout<<del->info<<" deleted"<<endl;
	temp->next = del->next;
	delete del;
}

void singlyTraverse(Node* head){
	if(head == NULL){
		cout<<"List is empty"<<endl;
		return;
	}

	Node* temp = head;
	while(temp != NULL){
		cout<<temp->info<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Node* head = NULL;
	int choice, data, pos;

	do{
		cout<<"\n-----Singly Linked List----"<<endl;
		cout<<"1. Insert at Beginning\n";
		cout<<"2. Insert at End\n";
		cout<<"3. Insert at Specific Point\n";
		cout<<"4. Delete at Beginning\n";
		cout<<"5. Delete at End\n";
		cout<<"6. Delete at Specific Point\n";
		cout<<"7. Traverse\n";
		cout<<"8. Exit\n";

		cout<<"Enter Your Choice: ";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter Data: ";
				cin>>data;
				insertBeginning(head,data);
				break;

			case 2:
				cout<<"Enter Data: ";
				cin>>data;
				insertEnd(head,data);
				break;

			case 3:
				cout<<"Enter Position and Data: ";
				cin>>pos>>data;
				insertSpecificPoint(head,data,pos);
				break;

			case 4:
				deleteBeginning(head);
				break;

			case 5:
				deleteEnd(head);
				break;

			case 6:
				cout<<"Enter Position: ";
				cin>>pos;
				deleteSpecificPoint(head,pos);
				break;

			case 7:
				singlyTraverse(head);
				break;

			case 8:
				cout<<"Exiting..."<<endl;
				break;

			default:
				cout<<"Invalid Input"<<endl;
		}

	}while(choice != 8);

	return 0;
}

