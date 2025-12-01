# include<iostream>
# define max 70
using namespace std;

class Stack{
	int Stack[max]; int top=-1;
public:
	void MakeEmptyStack(){
			top=-1;
			cout<<"Stack is Empty now.\n";
		}
	bool overflow(){
			if(top==max-1){
				return true;
			}	
			else{
				return false;
			}
		}
	
	bool underflow(){
			if(top==-1 || top<0){
				return true;
			}
			else{
				return false;
			}
		}
	
	void Push(int data){
			if(overflow()){
				cout<<"Stack is Full"<<endl;
			}
			else{
				top++;
				Stack[top]=data;
			}
		}
	
	void Pop(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
			}
			else{
				cout<<"Popped element is:";
				cout<<Stack[top]<<endl;
				top--;
				}
		}
	
	void Traverse(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
			}
			else{
				cout<<"Stack Elements from top to bottom are:"<<endl;
				for(int i=top; i>=0; i--){
					cout<<Stack[i]<<" "<<endl;
				}
			}
		}
	
	void Top(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
			}
			else{
				cout<<"Top element of stack is: "<<Stack[top]<<endl;
			}
		}
};
int main(){
	int a; int n; int data;
	Stack s;
	do{
		cout<<"\nChoose the following options:"<< endl;
		cout<<"1. Push operation.\n"
			<<"2. Pop operation.\n"
			<<"3. Make Stack Empty.\n"
			<<"4. Traverse Stack.\n"
			<<"5. Display Top.\n"
			<<"6. Exit.\n";
		cout<<"Enter your Choice (Sujal Meher Kayastha): ";
		cin>>a;
		switch(a){
			case 1:
				int n;
				cout<<"\nEnter Data:";
				cin>>data;
				s.Push(data);
				cout<<"Data Pushed."<<endl;
				break;
			
			case 2:
				s.Pop();
				break;
		
			case 3:
				s.MakeEmptyStack();
				break;
			
			case 4:	
				s.Traverse();
				break;
		
			case 5:
				s.Top();
				break;
				
			case 6:
				cout<<"Exiting Program."<<endl;
				break;
			
			default:
				cout<<"Choose from the options only."<<endl;
		}
	}
	while(a!=6);
	
return 0;
		
}
