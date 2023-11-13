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
        //v.resize(n, 0);
        adjList.resize(n, v);
    }
    void addEdge(int from, int to){
        adjList[from].push_back(to);
    }
    int shortestPath(int start, int end){
        set<int> visited;
        stack<int> s;
        int count=0;
        s.push(start);
        
        while(!s.empty()){
            int current = s.top();
            s.pop();
            
            if(current == end) return count;
            
            if(visited.find(current) == visited.end()){
                visited.insert(current);
                count++;
                for(int neighbor : adjList[current]){
                    if(visited.find(neighbor) == visited.end()){
                        s.push(neighbor);
                    }
                }
            }
        }
        return -1;
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
    int start, end;
    cin>>start>>end;
    cout<<g.shortestPath(start,end);
        
}