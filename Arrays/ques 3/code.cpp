#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    vector<string> a;
    int n;
    cin>>n;
    string val;
    for(int i=0;i<n;++i){
        cin>>val;
        a.push_back(val);
    }
    vector<string> unique;
    unordered_set<string> seen;
    for(string s : a){
        if(seen.find(s) == seen.end()){
            seen.insert(s);
            unique.push_back(s);
        }
    }
    cout<<"Updated array: ";
    for(string s : unique){
        cout<<s<<" ";
    }
}