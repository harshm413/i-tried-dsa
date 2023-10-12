#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &left, vector<int> &right, vector<int> &array){
    int i=0,j=0,k=0;
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]){
            array[k++]=left[i++];
        }
        else{
            array[k++]=right[j++];
        }
    }
    while(i<left.size()){
        array[k++]=left[i++];
    }
    while(j<right.size()){
        array[k++]=right[j++];
    }
}
void sort(vector<int> &array){
    if(array.size()<2){
        return;
    }
    int middle=array.size()/2;
    vector<int> left;
    for(int i=0;i<middle;++i){
        left.push_back(array[i]);
    }
    vector<int> right;
    for(int i=middle;i<array.size();++i){
        right.push_back(array[i]);
    }
    sort(left);
    sort(right);
    merge(left,right,array);
}
int main(){
    vector<int> array={23,76,33,91,26,35,40};
    cout<<"Before Sorting..."<<endl;
    for(int i=0;i<array.size();++i){
        cout<<array[i]<<" ";
    }
    sort(array);
    cout<<endl<<"After Sorting..."<<endl;
    for(int i=0;i<array.size();++i){
        cout<<array[i]<<" ";
    }
}