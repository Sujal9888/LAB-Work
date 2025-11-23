# include <iostream>
using namespace std;

int main(){
	int n,i=0,odd=0,even=0;
	int a[n];
	 cout<<"Enter no. of array:";
	 cin>> n;
	 cout<<"Enter array Element:";
	 for(i=0; i<n; i++){
	 	cin>>a[i];
	 }
	 for(i=0;i<n;i++){
	 	if(a[i]%2==0){
	 		even +=a[i];
		 }else{
		 	odd +=a[i];
		 }
	 }
cout<<"Odd Sum:"<<odd<<endl;
cout<<"Even Sum:"<<even<<endl;
 return 0;
}
