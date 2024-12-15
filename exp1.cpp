#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
struct Node{
    unsigned int rollno;
    char name[50];
    float sgpa;
};
class SDB{
    Node arr[10];
    int n;
    public:
    SDB(){
        n =0;
    }
    void accept();
    void bubbleSort();
    void insertionSort();
    void Lsearch();
    void Bsearch();
    void display();
};
void SDB::Lsearch(){
    int rol;
    cout<<"Enter roll no to serach: ";
    cout<<rol;
    cout<<endl;
    for(int i = 0 ; i < n ; i++){
        if(arr[i].rollno==rol){
            cout<<"found";
            return;
        }
    }
    cout<<"Not found";
}
void SDB::Bsearch(){
    int rol;
    cout<<"Enter rollno to found: ";
    cin>>rol;
    cout<<endl;
    int s,l,mid;
    s=0;
    mid=n-1;
    while(s<=l){
        mid=(s+l)/2;
        if(arr[mid].rollno==rol){
            cout<<"found";
            return;
        }
        else if(arr[mid].rollno>rol){
            l=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<"Not found";
}
void SDB::accept(){
    cout<<"Enter number of students: ";
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cout<<"Enter Roll no: ";
        cin>>arr[i].rollno;
        cout<<endl;
        cout<<"Enter name: ";
        cin>>arr[i].name;
        cout<<endl;
        cout<<"Enter SGPA: ";
        cin>>arr[i].sgpa;
        cout<<endl;
    }
    
}
void SDB::bubbleSort(){
    for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j<n-1 ; j++){
            if(arr[j].rollno>arr[j+1].rollno){
                Node temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void SDB::insertionSort(){
    for(int i = 1 ; i < n ; i++){
        int j = i-1;
        Node temp=arr[i];
        while(j>=0 && strcmp(arr[j].name,temp.name)>0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void SDB::display(){
    cout<<"Roll no"<<setw(10)<<"Name"<<setw(10)<<"SGPA"<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i].rollno<<setw(20)<<arr[i].name<<setw(10)<<arr[i].sgpa<<endl;
    }
}

int main() {
   SDB s;
   s.accept();
   s.bubbleSort();
   s.display();
   s.insertionSort();
  s.display();

    return 0;
}
