# include<iostream>
# define max 50
using namespace std;
int main(){
int a; int count=0;	int arr[max];
do{
	cout<<"\n Choose from the following options:"<<endl;
	cout<<" 1. Insert data in array.\n"
		<<" 2. Display element of array.\n"
		<<" 3. Delete element of array.\n"
		<<" 4. Update element of array.\n"
		<<" 5. Search element of array.\n"
		<<" 6. Find  minimum of array.\n"
		<<" 7. Find maximum of array.\n"
		<<" 8. Exit array.\n ";
		
		cout<<"\n Enter your Choice: ";
		cin>>a;
		switch(a){
			case 1:{
				if(count==max){
					cout<<" Array is full"<<endl;
				}
				else{
					cout<<" Enter element:";
					cin>>arr[count];
					count++;
				}
				break;
			}
			case 2:{
				if(count==-1){
					cout<<" Array is empty."<<endl;
				}
				else{
					cout<<" Array are:";
					for(int i=0;i<count;i++){
						cout<<arr[i]<<" ";
					}
					cout<<"\n";
				}
				break;
			}
			case 3:{
				cout<<"\n Enter position of array to delete: ";
				int i,j;
				cin>>j;
				if(j>count){
					cout<<" Array doesn't exist "<<endl;
				}	
				else{
					for(i=j-1;i<count-1;i++){
						arr[i]=arr[i+1];
					}
					count--;
				} 
				break;
			}
			case 4:{
				cout<<"\n Enter position of element to update: ";
				int update;
				cin>>update;
				if(update>count){
					cout<<" No element ";
				}	
				else{
					cout<<"\n Enter element:";
					int b;
					cin>>b;
					arr[update-1]=b;
				}
				break;
			}
			case 5:{
				cout<<"\n Enter element to search: ";
				int search; int f=0;
				cin>>search;
				for(int i=0; i<count;i++){
					if(arr[i]==search){
						cout<<" Searched element found at: "<<(i+1)<<endl;
					f=1;
					}
				}
				if(f!=1){
				cout<<" Not found. "<<endl;
			}
			break;
			}
			case 6:{
				cout<<"\n Minimum of array is: ";
				int s=arr[0];
				for(int i=0;i<count;i++){
					if(arr[i]<s){
						s=arr[i];
					}
				}
				cout<<s<<endl;
				break;
			}
				
			case 7:{
				cout<<"\n Maximum of array is: ";
				int l=arr[0];
				for(int i=0;i<count-1;i++){
					if(arr[i]>l){
						l=arr[i];
					}
				}
				cout<<l<<endl;
				break;
			}
			case 8:{
				cout<<"\n Existing program."<<endl;
				break;
			}
		}
	}
	while(a!=8);
	return 0;
}
		

