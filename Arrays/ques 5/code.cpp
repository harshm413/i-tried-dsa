#include<iostream>
#include<list>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<int> ids;
    int id;
    for(int i=0;i<n;++i){
        cin>>id;
        ids.push_back(id);
    }
    cout<<"Removing out-of-stock products"<<endl;
    ids.remove(0);
    cout<<"Updated array of product IDs: ";
    for(int id : ids){
        cout<<id<<" ";
    }
}