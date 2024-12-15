#include <iostream>
// #include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

class stack{
    char exp[50];
    int top;
    public:
     stack(){
        top=-1;
     }
     void push(char ch){
        top++;
        exp[top]=ch;
     }
     char pop(){
        char temp = exp[top];
        top--;
        return temp;
     }
     char peek(){
        return exp[top];
     }
};
class Expression{
    char exp[50];
    unsigned int n =0;
    public:
    void accept(){
        cout<<"Enter the expression: ";
        cin>>exp;
        cout<<endl;
        n=strlen(exp);
    }
    string postfix(){
        string ans="";
        stack s;
        s.push('#');
        for(int i = 0 ; exp[i]!='\0' ; i++){
            if(isalpha(exp[i])){
                ans+=exp[i];
            }
            else if(exp[i]==')'){
                while(s.peek()!='('){
                    ans+=s.pop();
                }
                s.pop();
            }
            else if(insP(s.peek())<incP(exp[i])){
                s.push(exp[i]);
            }
            else{
                while(insP(s.peek()>=exp[i])){
                    ans+=s.pop();
                }
            }
            
        }
        while(s.peek()!='#'){
                ans+=s.pop();
            }
        return ans;
    }


        string prefix(){
        string ans="";
        stack s;
        s.push('#');
        for(int i = n ; i>=0 ; i--){
            if(isalpha(exp[i])){
                ans+=exp[i];
            }
            else if(exp[i]=='('){
                while(s.peek()!=')'){
                    ans+=s.pop();
                }
                s.pop();
            }
            else if(insP(s.peek())<incP(exp[i])){
                s.push(exp[i]);
            }
            else{
                while(insP(s.peek()>=exp[i])){
                    ans+=s.pop();
                }
            }
            
        }
        while(s.peek()!='#'){
                ans+=s.pop();
            }
        return ans;
    }





    int insP(char ch){
        switch (ch){
            case '(':case ')': return 0;
            case '+':case '-':return 1;
            case '*':case '/': return 2;
            case '#':return -1;
        }
        return 0;
    }

    int incP(char ch){
        switch (ch){
            case '(':case ')': return 3;
            case '+':case '-':return 1;
            case '*':case '/': return 2;
            case '#':return -1;
        }
        return 0;
    }
};
int main(){
    Expression e;
    e.accept();
    // char pf[50];
    cout<<e.postfix();
    cout<<endl;
    string pre = e.prefix();
    std::reverse(pre.begin(),pre.end());    
    cout<<pre;
}
