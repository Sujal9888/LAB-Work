#include<iostream>
using namespace std;

class Height{
	int meter;
	int centimeter;
	public:
		Height(int m=0,int cm=0){
			meter=m;
			centimeter=cm;
		}
		friend Height operator+(Height &h1,Height &h2);
		void disp(){
			cout<<meter<<" m,"<<centimeter<<" cm"<<endl;
		}
};
Height operator+(Height &h1,Height &h2){
	Height res;
	res.meter=h1.meter+h2.meter;
	res.centimeter=h1.centimeter+h2.centimeter;
	if(res.centimeter>=100){
		res.meter=res.meter+res.centimeter/100;
		res.centimeter=res.centimeter%100;
	}
return res;
}
int main(){
	Height h1(4,5);
	Height h2(5,4);
	Height h3=h1+h2;
	cout<<"Height :";
	h3.disp();
return 0;
}

