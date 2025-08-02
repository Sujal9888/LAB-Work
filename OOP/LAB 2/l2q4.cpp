#include<iostream>
using namespace std;
class Time{
	int hh;
	int mm;
	int ss;
public:
	Time( int h=0,int m=0,int s=0){
		hh=h;
		mm=m;
		ss=s;
	}
	Time add(Time t1){
		Time temp;
		temp.ss = ss + t1.ss;
		temp.mm = mm + t1.mm;
		temp.hh = hh +t1.hh;
		
	if(temp.ss>=60){
		temp.mm += temp.ss/60;
		temp.ss=temp.ss % 60;
	}
	if(temp.mm>=60){
		temp.hh += temp.mm/60;
		temp.mm= temp.mm % 60;
	}
	return temp;
	}
	void display(){
		cout<<"HH:MM:SS="<<hh<<":"<<mm<<":"<<ss<<endl;
	}
};
int main(){
	Time t1(1,68,99),t2(34,89,60),t3;
	cout<<"Two times are :"<<endl;
	t1.display();
	t2.display();
	t3= t1.add(t2);
	cout<<"Sum:";
	t3.display();
	return 0;
}
