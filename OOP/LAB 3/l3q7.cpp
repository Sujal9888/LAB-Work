#include<iostream>
using namespace std;

class Distance{
	int meter;
	int centimeter;
	public:
		Distance(int m=0,int cm=0){
			meter=m;
			centimeter=cm;
		}
		bool operator<=(Distance &d){
			int a,b;
			a=meter*100+centimeter;
			b=d.meter*100+d.centimeter;
			return a<=b;
		}
		void disp(){
			cout<<meter<<" m,"<<centimeter<<" cm"<<endl;
		}
};
int main(){
	Distance d1(3,4);
	Distance d2(4,3);
	d1.disp();
	d2.disp();
	if(d1<=d2){
		cout<<" d1 is less than or equal to d2 "<<endl;
	}else{
		cout<<"d1 is greater than d2"<<endl;
	}
return 0;
}
