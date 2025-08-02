#include<iostream>
using namespace std;

class Time{
	int hrs;
	int min;
	int sec;
	public:
		Time(int h=0,int m=0,int s=0){
			hrs=h;
			min=m;
			sec=s;
		}
		Time operator+(Time t){
			Time res;
			res.sec=sec+t.sec;
			res.sec=res.sec%60;
			res.min=min+t.min+res.sec/60;
			res.min=res.min%60;
			res.hrs=hrs+t.hrs+res.min/60;
			return res;
		}
		void disp(){
			cout<<hrs<<":"<<min<<":"<<sec<<endl;
		}
};
int main(){
	Time t1(1,10,25);
	Time t2(4,15,30);
	Time t3=t1+t2;
	cout<<"Time: ";
	t3.disp();
return 0;
}
