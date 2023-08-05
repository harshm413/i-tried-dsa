#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[50];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    map<int,int> frequency;
    vector<int> orderOfInsert;
    for(int i=0;i<n;++i){
        if(frequency.find(a[i]) == frequency.end()){
            orderOfInsert.push_back(a[i]);
        }
        frequency[a[i]]+=1;
    }
    cout<<"Element"<<"   "<<"Frequency"<<endl;
    for(int element : orderOfInsert){
        cout<<element<<"         "<<frequency[element]<<endl;
    }
}