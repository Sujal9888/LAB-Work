#include<iostream>
using namespace std;
class Student{
	double id;
	double marks;
	public:
		Student(){
			id=1;
			marks=50;
		}
		Student(double a, double b){
			id=a;
			marks=b;
		}
		void display(){
			cout<<"Id:"<<id<<endl;
			cout<<"Marks:"<<marks<<endl;
		}
};
int main(){
	Student s1;
	s1.display();
	Student s2(103,59.8);
	s2.display();
	Student s3(s1);
	s3.display();
	return 0;
}
