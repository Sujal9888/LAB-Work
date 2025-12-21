#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <iomanip>
#include<algorithm>
using namespace std;

int precedence(char op) {
    if(op=='^' || op=='$') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}

string intToStr(int n) {
    if(n==0) return "0";
    string s="";
    while(n>0) { s = char(n%10+'0') + s; n/=10; }
    return s;
}

string stackToString(stack<char> s) {
    string t = "";
    while(!s.empty()) { t = s.top() + t; s.pop(); }
    return t;
}

void printConversionRow(char scanned, const string &output, const string &stackStr) {
    cout << left << setw(10) << scanned
         << setw(20) << output
         << setw(15) << stackStr << endl;
}

void printEvalRow(char scanned, const string &operation, stack<string> display) {
    cout << left << setw(12) << scanned
         << setw(18) << operation;
    string stackStr="";
    while(!display.empty()){ stackStr = display.top() + " " + stackStr; display.pop(); }
    cout << stackStr << endl;
}

string infixToPostfix(const string &infix) {
    stack<char> opstack;
    stack<char> postfixStack;
    string output;

    cout << "Char   Postfix        OpStack \n";
    cout << "----------------------------------\n";

    for(int i=0; i<infix.length(); i++){
        char a = infix[i];

        if(isalnum(a)){
            postfixStack.push(a);
        }
        else if(a=='(' || a=='{' || a=='['){
            opstack.push(a);
        }
        else if(a==')' || a=='}' || a==']'){
            char open;
            if(a==')') open='(';
            else if(a=='}') open='{';
            else open='[';

            while(!opstack.empty() && opstack.top()!=open){
                postfixStack.push(opstack.top());
                opstack.pop();
            }
            if(opstack.empty()) return "Error: Mismatched Brackets";
            opstack.pop();
        }
        else{
            while(!opstack.empty() && precedence(opstack.top())>=precedence(a) &&
                  opstack.top()!='(' && opstack.top()!='{' && opstack.top()!='['){
                if((opstack.top()=='$' && a=='$') || (opstack.top()=='^' && a=='^') ||
                   (opstack.top()=='$' && a=='^') || (opstack.top()=='^' && a=='$')){
                    break;
                }
                postfixStack.push(opstack.top());
                opstack.pop();
            }
            opstack.push(a);
        }

        string postStr = "";
        stack<char> temp = postfixStack;
        while(!temp.empty()){ postStr = temp.top() + postStr; temp.pop(); }
        string opStr = stackToString(opstack);
        printConversionRow(a, postStr, opStr);
    }

    while(!opstack.empty()){
        if(opstack.top()=='(' || opstack.top()=='{' || opstack.top()=='[') return "Error: Extra Open Bracket";
        postfixStack.push(opstack.top());
        opstack.pop();
    }

    string finalPostfix="";
    while(!postfixStack.empty()){ finalPostfix = postfixStack.top() + finalPostfix; postfixStack.pop(); }
    return finalPostfix;
}

string infixToPrefix(const string &infix) {
    stack<char> operators;
    string prefix = "";

    cout << "Char   Prefix         OpStack \n";
    cout << "----------------------------------\n";

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix = c + prefix;
        }
        else if (c == ')' || c == '}' || c == ']') {
            operators.push(c);
        }
        else if (c == '(' || c == '{' || c == '[') {
            while (!operators.empty() && (operators.top() != ')' && operators.top() != '}' && operators.top() != ']')) {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
        else {
            while (!operators.empty() && 
                  ((precedence(operators.top()) > precedence(c)) || 
                   (precedence(operators.top()) == precedence(c) && c != '^' && c != '$'))) {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.push(c);
        }

        string opStr = stackToString(operators);
        printConversionRow(c, prefix, opStr);
    }

    while (!operators.empty()) {
        prefix = operators.top() + prefix;
        operators.pop();
    }

    return prefix;
}


int evalPostfix(const string &postfix){
    stack<int> valStack;
    stack<string> display;

    cout << "\n" << left << setw(12) << "Scanned"
         << setw(18) << "Result"
         << "OperandStack" << endl;
    cout << "-----------------------------------------\n";

    for(int i=0;i<postfix.length();i++){
        char c = postfix[i];
        string operation;
        if(isdigit(c)){
            valStack.push(c-'0');
            display.push(string(1,c));
            printEvalRow(c,string(1,c),display);
        } else {
            int b = valStack.top(); valStack.pop();
            int a = valStack.top(); valStack.pop();
            string sb = display.top(); display.pop();
            string sa = display.top(); display.pop();
            int res;
            switch(c){
                case '+': res=a+b; operation=sa+"+"+sb+"="+intToStr(res); break;
                case '-': res=a-b; operation=sa+"-"+sb+"="+intToStr(res); break;
                case '*': res=a*b; operation=sa+"*"+sb+"="+intToStr(res); break;
                case '/': res=a/b; operation=sa+"/"+sb+"="+intToStr(res); break;
                case '^': case '$': res=pow(a,b); operation=sa+"^"+sb+"="+intToStr(res); break;
            }
            valStack.push(res);
            display.push(intToStr(res));
            printEvalRow(c,operation,display);
        }
    }
    return valStack.top();
}

int evalPrefix(const string &prefix){
    stack<int> valStack;
    stack<string> display;

    cout << "\n" << left << setw(12) << "Scanned"
         << setw(18) << "Result"
         << "OperandStack" << endl;
    cout << "-----------------------------------------\n";

    for(int i=prefix.length()-1;i>=0;i--){
        char c = prefix[i];
        string operation;
        if(isdigit(c)){
            valStack.push(c-'0');
            display.push(string(1,c));
            printEvalRow(c,string(1,c),display);
        } else {
            int b = valStack.top(); valStack.pop();
            int a = valStack.top(); valStack.pop();
            string sb = display.top(); display.pop();
            string sa = display.top(); display.pop();
            int res;
            switch(c){
                case '+': res=a+b; operation=sa+"+"+sb+"="+intToStr(res); break;
                case '-': res=a-b; operation=sa+"-"+sb+"="+intToStr(res); break;
                case '*': res=a*b; operation=sa+"*"+sb+"="+intToStr(res); break;
                case '/': res=a/b; operation=sa+"/"+sb+"="+intToStr(res); break;
                case '^': case '$': res=pow(a,b); operation=sa+"^"+sb+"="+intToStr(res); break;
            }
            valStack.push(res);
            display.push(intToStr(res));
            printEvalRow(c,operation,display);
        }
    }
    return valStack.top();
}

int main(){
    int choice;
    string inf;

    do{
        cout << "\nChoose from the following options.\n";
        cout<< "1. Infix to Postfix\n"
			<<"2. Infix to Prefix\n"
			<<"3. Evaluate Postfix\n"
			<<"4. Evaluate Prefix\n"
			<<"5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter infix Expression: ";
                getline(cin,inf);
                cout << "\nFinal Postfix: " << infixToPostfix(inf) << "\n";
                break;
            case 2:
                cout << "Enter infix Expression: ";
                getline(cin,inf);
                cout << "\nFinal Prefix: " << infixToPrefix(inf) << "\n";
                break;
            case 3:
                cout << "Enter Postfix Expression: ";
                getline(cin,inf);
                cout << "\nResult = " << evalPostfix(inf) << "\n";
                break;
            case 4:
                cout << "Enter Prefix Expression: ";
                getline(cin,inf);
                cout << "\nResult = " << evalPrefix(inf) << "\n";
                break;
            case 5:
                cout << "Exiting program.\n"; break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice!=5);

    return 0;
}
