#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
class Graph{
    public:
        int V;
        list<int> *adjList;
        Graph(int v){
            V=v;
            adjList=new list<int>[V];
        }
        void add_edge(int u, int v, bool bidir=true){
            adjList[u].push_back(v);
            if(bidir){
                adjList[v].push_back(u);
            }
        }
        void print_adj(){
            for(int i=0; i<V; i++){
                cout<<i<<"->";
                for(int node:adjList[i]){
                    cout << node << ",";    
                }
                cout << endl;
            }
        }
    void bfs(int src){
        //traverse all nodes
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            // cout << q.front() << endl;
            int node = q.front();
            cout<<node<<endl;
            q.pop();
            for(int neigh:adjList[node]){
                if (!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }
        }
    }
};
int main(){
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,3);
    g.add_edge(1,3);
    g.add_edge(3,2);
    // g.print_adj();
    g.bfs(0);
}