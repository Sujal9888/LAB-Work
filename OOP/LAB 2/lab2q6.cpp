#include<iostream>
using namespace std;
class Account{
	int acc_no;
	float balance;
	static float min_balance;
	public:
		void read(){
			cout << "Enter account number:";
			cin >> acc_no;
			cout << "Enter balance:";
			cin >> balance;
		}
		void display(){
			cout << "Account Number:"<<acc_no<<endl;
			cout << "Balance:"<<balance<<endl;
		}
		static void displayminbalance(){
			cout << "Minimum Balance:"<<min_balance<<endl;
		}
};
float Account :: min_balance=1000;
int main(){
	Account a[5];
	cout <<"Enter Account deatils"<<endl;
	for(int i=0;i<5;i++){
		cout <<"Account"<<i+1<<":"<<endl;
		a[i].read();
	}
cout<<"---Account details---"<<endl;
	for(int i=0;i<5;i++){
		cout<<"Account number of "<<i+1<<":"<<endl;
		a[i].display();
	}
	cout<<"\n Minimum balance"<<endl;
	Account::displayminbalance();

return 0;
}
