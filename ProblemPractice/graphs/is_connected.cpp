#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void isConnectedDFS(int **adj_list, int v, int src, bool *visited){
    visited[src] = true;
    for(int i=0; i<v; i++){
       if(i==src){
           continue;
       }
       if(adj_list[src][i] && !visited[i]){
       isConnectedDFS(adj_list, v, i, visited);
       }
    }

}
int main(){
    int v,e;
    cin>>v>>e;
    int **adj_list = new int*[v];
    for(int i=0;i<v;i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s,f;
        cin>>s>>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    bool* visited = new bool[v]{0};
    isConnectedDFS(adj_list, v,0, visited);
    bool done=false;
    for(int i=0;i<v;i++){
    
        if(!visited[i]){
            done=true;
        }
    }
   cout<<boolalpha<<!done<<endl;
}