#include<iostream>
#include<vector>
#include<set>
#include<stack>

using namespace std;

class Graph{
    vector< vector<int> > adjList;
    public:
    Graph(int n){
        vector<int> v;
        adjList.resize(n, v);
    }
    void addEdge(int from, int to){
        adjList[from].push_back(to);
    }
    void dfs(int start){
        set<int> visited;
        stack<int> s;
        
        s.push(start);
        
        while(!s.empty()){
            int current = s.top();
            s.pop();
            
            if(visited.find(current) == visited.end()){
                cout<<current<<" ";
                visited.insert(current);
                for(int i=adjList[current].size()-1;i>=0;--i){
                    if(visited.find(adjList[current][i]) == visited.end()){
                        s.push(adjList[current][i]);
                    }
                }
            }
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int start;
    cin>>start;
    cout<<"Depth First Traversal starting from vertex "<<start<<":\n";
    g.dfs(start);
}