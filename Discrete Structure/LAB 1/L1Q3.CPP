# include<iostream>
using namespace std;
int main(){
	double num;
	cout<<"Enter a real number:";
	cin>>num;
	
	int ceilval;
	int floorval;
	floorval=(int)num;
	
	if(num<0 && num!=floorval){
		floorval--;
	}
	ceilval=(int)num;
	if(num>0 && num!=ceilval){
		ceilval++;
	}
	if(num==(int)num){
		ceilval=(int)num;
	}
	cout<<"Ceiling:"<<ceilval<<endl;
	cout<<"Floor:"<<floorval<<endl;
	return 0;
}
