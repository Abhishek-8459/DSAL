#include <iostream>
#include <string.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
};
class stack{
    node* exp[50];
    public :int top;
    public:
     stack(){
        top=-1;
     }
     void push(node* ch){
        top++;
        exp[top]=ch;
     }
     node* pop(){
        node* temp = exp[top];
        top--;
        return temp;
     }
     node* peek(){
        return exp[top];
     }
};

class exptree{
    char exp[50];
    unsigned int len;
    
    public :
    exptree(){
        len=0;
    }
    void accept(){
        cout<<"enter the expression: ";
        cin>>exp;
        len = strlen(exp);
    }
    node*  postToTree(){
        stack s;
        for(int i = 0 ; i < len ; i++){
            node *newp = new node;
            newp->data=exp[i];
            if(isalpha(exp[i])){
                newp->left=NULL;
                newp->right=NULL;
                s.push(newp);
            }
            else{
                newp->right= s.pop();
                newp->left=s.pop();
                s.push(newp);
            }
        }
        return s.pop();
    }
    void inorder(node *temp){
        stack s;
        s.push(NULL);
        while(temp!=NULL){
            while(temp!=NULL){
                s.push(temp);
                temp=temp->left;
            }
            temp =s.pop();
            while(temp!=NULL){
                cout<<temp->data;
                if(temp->right!=NULL){
                    temp=temp->right;
                    break;
                }
                else{
                    temp=s.pop();
                }
            }
        }
    }

    void preorder(node* temp){

        stack s ;
        s.push(NULL);
        while(temp!=NULL){
            while(temp!=NULL){
                cout<<temp->data;
                if(temp->right!=NULL){
                    s.push(temp->right);
                }
                temp=temp->left;
            }
            temp=s.pop();
        }
    }
    void postorder(node* temp){
        stack s;
        s.push(NULL);
        bool flag[50]={false};
        while(temp!=NULL){
            while(temp!=NULL){
                s.push(temp);
                flag[s.top]=true;
                if(temp->right!=NULL){
                    s.push(temp->right);
                }
                temp=temp->left;
            }
            while(flag[s.top]){
                temp=s.pop();
                cout<<temp->data;
            }
            temp=s.pop();
        }
    }


};
int  main(){
    exptree e;
    e.accept();
    node* root = e.postToTree();
    e.inorder(root);
    cout<<endl;
    e.preorder(root);
    cout<<endl;
    e.postorder(root);
}
