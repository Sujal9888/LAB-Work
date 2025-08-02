#include<iostream>
using namespace std;

class Student{
	int visit;
	public:
	Student(int v=0){
		visit=v;
	}
	Student operator++(int){
		Student temp=*this;
		visit++;
		return temp;
	}
	void disp(){
		cout<<"No.of visit: "<<visit<<endl;
	}
};
int main(){
	Student s1(4);
	cout<<"Before visit: ";
	s1.disp();
	s1++;
	cout<<"After visit: ";
	s1.disp();
return 0;
}
