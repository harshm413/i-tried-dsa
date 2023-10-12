#include<iostream>
#include<vector>
using namespace std;
class Tree{
    struct Node{
        int value;
        Node *left,*right;
        Node(int val){
            value=val;
            left=right=nullptr;
        }
    };
    Node *root;
    int max(int a,int b){
        if(a>=b) return a;
        else return b;
    }
    Node* insertLevelOrder(vector<int> &array, int i, int n){
        Node *root=nullptr;
        if(i<n){
            root=new Node(array[i]);
            root->left=insertLevelOrder(array,2*i+1,n);
            root->right=insertLevelOrder(array,2*i+2,n);
        }
        return root;
    }
    void preOrder(Node *root){
        if(root==nullptr)
            return;
    
        cout<<root->value<<", ";
        preOrder(root->left);
        preOrder(root->right);
    }
    int height(Node *root){
        if(root==nullptr){
            return -1;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    void printNodeAtDistance(Node *root, int dist){
        if(root==nullptr) return;
        if(dist==0){
            cout<<root->value<<" ";
        }
        printNodeAtDistance(root->left,dist-1);
        printNodeAtDistance(root->right,dist-1);
    }
    bool isBinarySearchTree(Node *root, int min, int max){
        if(root==nullptr){
            return true;
        }
        if(root->value<min || root->value>max){
            return false;
        }
        return isBinarySearchTree(root->left,min,root->value-1)
            && isBinarySearchTree(root->right,root->value+1,max);
    }
    public:
    Tree(){
        root=nullptr;
    }
    void insertLevelOrder(vector<int> &array){
        root=insertLevelOrder(array, 0, array.size());
    }
    void preOrder(){
        preOrder(root);
        cout<<endl;
    }
    void printNodeAtDistance(int dist){
        printNodeAtDistance(root,dist);
    }
    int height(){
        return height(root);
    }
    void levelOrder(){
        for(int i=0;i<=height();++i){
            printNodeAtDistance(i);
            cout<<endl;
        }
    }
    bool isBinarySearchTree(){
        return isBinarySearchTree(root,INT_MIN,INT_MAX);
    }
};
int main(){
    Tree t;
    vector<int> array={34,76,12,78,45,23,89};
    t.insertLevelOrder(array);
    t.preOrder();
    cout<<"Height of the tree is "<<t.height()<<"."<<endl;
    t.levelOrder();
    if(t.isBinarySearchTree()){
        cout<<"Yes. It is a binary search tree."<<endl;
    }else{
        cout<<"No. It is not a binary search tree."<<endl;
    }
    cout<<"End of program.";
}
