#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> strings;
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        strings.push_back(s);
    }
    char c;
    cin>>c;
    cout<<"Number of strings starting with the letter "<<c<<" : ";
    int cnt;
    for(string s : strings){
        if(s[0] == c){
            ++cnt;
        }
    }
    cout<<cnt;
}