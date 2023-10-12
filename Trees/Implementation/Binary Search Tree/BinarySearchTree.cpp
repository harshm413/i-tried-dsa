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
    public:
    Tree(){
        root=nullptr;
    }
    void insert(int val){
        if(root==nullptr){
            root=new Node(val);
            return;
        }

        Node *current=root;
        while(true){
            if(val<current->value){
                if(current->left==nullptr){
                    current->left=new Node(val);
                    break;
                }
                current=current->left;
            }
            else if(val>current->value){
                if(current->right==nullptr){
                    current->right=new Node(val);
                    break;
                }
                current=current->right;
            }
        }
    }
    bool find(int val){
        Node *current=root;
        while(current!=nullptr){
            if(val<current->value)
                current=current->left;
            else if(val>current->value)
                current=current->right;
            else
                return true;
        }
        return false;
    }
    void preOrder(){
        preOrder(root);
        cout<<endl;
    }
    int height(){
        return height(root);
    }
    void printNodeAtDistance(int dist){
        printNodeAtDistance(root,dist);
    }
    void levelOrder(){
        for(int i=0;i<=height();++i){
            printNodeAtDistance(i);
            cout<<endl;
        }
    }
};
int main(){
    int size=7;
    int a[]={34,76,12,78,45,23,89};
    Tree t;
    for(int i=0;i<size;++i){
        t.insert(a[i]);
    }
    t.preOrder();
    cout<<"Height of the tree is "<<t.height()<<"."<<endl;
    t.levelOrder();
    cout<<"End of program.";
}