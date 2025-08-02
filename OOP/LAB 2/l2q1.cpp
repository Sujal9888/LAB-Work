#include<iostream>
using namespace std;
class Largest{

		int a;
		int b;
	public:
	void getnumber(){
		cout<<"Enter 1st number:";
		cin>>a;
		cout<<"Enter 2nd number:";
		cin>>b;
	}
	void display(){
		if(a>b){
		cout<<a<<"number is largest"<<endl;
	}
		else{
		cout<<b<<" number is largest"<<endl;
		}
	}
};
int main(){
	Largest l;
	l.getnumber();
	l.display();

	return 0;
}
