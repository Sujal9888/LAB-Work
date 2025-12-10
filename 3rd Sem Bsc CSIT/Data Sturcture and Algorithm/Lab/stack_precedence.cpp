#include<iostream>
#include<stack>
using namespace std;

int precedence(char a){
	if(a=='^' || a=='$') return 3;
	if(a=='*' || a=='/' || a=='%') return 2;
	if(a=='+'|| a=='-') return 1;
	return 0;
}
 string postfix(string infix){
 	stack<char> opstack;
 	stack<char> postfix;
 	for(int i=0; i<infix.length(); i++){
 		char a=infix[i];
 		
 		if(isalnum(a)){
 			postfix.push(a);
		 }
		 else if(a=='(' || a=='{' || a=='['){
		 	opstack.push(a);
		 }
		 else if(a==']' || a=='}' || a==')'){
		 	char open;
		 if(a==')') open='(';
		else if (a=='}') open='{';
		else open='[';
		
		while(!opstack.empty() && opstack.top()!=open){
			postfix.push(opstack.top());
			opstack.pop();
		}
		if(opstack.empty()){
			return "Error: Mismatched Brackets";
		}
		opstack.pop();
	}
	else{
		
		while( !opstack.empty() && precedence(opstack.top())>=precedence(a) &&
		 opstack.top() !='(' && opstack.top() !='{' && opstack.top() !='['){
		 	if((opstack.top()=='$' && a=='$') || (opstack.top()=='^' && a=='^') || (opstack.top()=='$' && a=='^') || (opstack.top()=='^' && a=='$')){
		 		break;
			 }
			 postfix.push(opstack.top());
			 opstack.pop();
			 }
		 opstack.push(a);
		 }
	}
	 
	 while(!opstack.empty()){
	 	if(opstack.top()=='(' || opstack.top()=='{' || opstack.top()=='['){
	 		return "Error: Extra Open Bracket";
		 }
		 postfix.push(opstack.top());
		 opstack.pop();
	}
	string post="";
	while(!postfix.empty()){
		post=postfix.top()+post;
		postfix.pop();
		}
	 	return post;
	 }
	 
int main(){
	string infix;
	cout<<"Enter Expression: ";
	cin>>infix;
	cout<<"Postfix Expression is : "<<postfix(infix)<<endl;

	return 0;
}
 
