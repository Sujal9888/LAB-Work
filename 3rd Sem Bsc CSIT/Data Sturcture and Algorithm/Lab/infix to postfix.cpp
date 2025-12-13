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

    cout << "Char   Postfix        OpStack \n";
    cout << "----------------------------------\n";

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
            while(!opstack.empty() && precedence(opstack.top())>=precedence(a) &&
                  opstack.top()!='(' && opstack.top()!='{' && opstack.top()!='['){
                if((opstack.top()=='$' && a=='$') || (opstack.top()=='^' && a=='^') ||
                   (opstack.top()=='$' && a=='^') || (opstack.top()=='^' && a=='$')){
                    break;
                }
                postfix.push(opstack.top());
                opstack.pop();
            }
            opstack.push(a);
        }

        cout << a << "      ";

        stack<char> t1 = postfix;
        string s1="";
        while(!t1.empty()){ 
		s1 = t1.top() + s1; t1.pop();
		 }
        cout << s1 << "\t \t";

        stack<char> t2 = opstack;
        string s2="";
        while(!t2.empty()){
		 s2 = t2.top() + s2; t2.pop(); 
		 }
        cout << s2 << endl;
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
    cout<<"\nPostfix Expression is : "<<postfix(infix)<<endl;
    return 0;
}

