#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

template <typename T>
class Graph{
    map<T, list<T> > adjList;
public:
    Graph(){
        
    }   
    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printAdj(){
        // for(Pair<T, list<T>> row: adjList){
        // }instead type of pair, use auto
        for(auto row: adjList){
            cout<< row.first << "->";
            for(auto col: row.second){
                cout << col<< ";";
            }
            cout << endl;
        }
    }
    voud bfs(int src){
        //traverse all nodes
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neigh:adjList)
        }
    }
};
int main(){
    Graph<string> g;
    g.addEdge("Geetika", "Jay");
    g.addEdge("Amrit","Jay");
    g.addEdge("Mummy", "Jay");
    g.printAdj();
}
