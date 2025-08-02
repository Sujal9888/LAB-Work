#include<iostream>
using namespace std;
class ticketbooth{
	static int pv; // People visited
	static int ts; //Ticket sold
	static float tac; // Total amount collected
	static float tp; // Ticket price   
	public:
		ticketbooth(){}
	static void visitoronly(){
		pv++;
	}
	static void ticketsold(){
		pv++;
		ts++;
		tac+=tp;
	}
	static void display(){
		cout<<"Ticketbooth Report"<<endl;
		cout<<"No. of people visited:"<<pv<<endl;
		cout<<"Tickets sold:"<<ts<<endl;
		cout<<"Total ammount collected:Rs"<<tac<<endl;
	}
};
int ticketbooth :: pv=0;
int ticketbooth :: ts=0;
float ticketbooth :: tac=0;
float ticketbooth :: tp=2.5;
int main(){
	ticketbooth::visitoronly();
	ticketbooth::ticketsold();
	ticketbooth::ticketsold();
	ticketbooth::visitoronly();
	ticketbooth::display();
	return 0;

}
