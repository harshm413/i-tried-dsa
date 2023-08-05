#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int pos;
    cin>>pos;
    int val;
    cin>>val;
    cout<<"Original array: ";
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    if(pos>n){
        cout<<"Invalid position!";
    }
    else{
        for(int i=n-1;i>pos-2;--i){
            a[i+1]=a[i];
        }
        a[pos-1]=val;
        cout<<"Updated array: ";
        for(int i=0;i<n+1;++i){
            cout<<a[i]<<" ";
        }
    }
}