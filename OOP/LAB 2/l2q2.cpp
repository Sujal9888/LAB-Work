# include<iostream>
using namespace std;
class Temperature{

	double f;
public:
	void getdata(){
		cout<<"Enter temperature in farenheit:";
		cin>>f;
	}
	void display(){
		cout<<f<<"F into Celsius is:"<< (f-32)*5/9<<"C"<<endl;	
		}
};
int main()
{
	Temperature a;
	a.getdata();
	a.display();
	return 0;
	}
