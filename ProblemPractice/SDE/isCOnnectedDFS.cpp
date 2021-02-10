#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void addEdge(int **matrix, int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void isConnectedDFS(int **matrix, int v, int src, bool *visited){
    visited[src] = true;
    for(int i=0; i<v; i++){
       if(i==src){
           continue;
       }
       if(matrix[src][i] && !visited[i]){
       isConnectedDFS(matrix, v, i, visited);
       }
    }

}
int main(){
    int V=5;
    int **matrix = new int*[V];
    for(int i=0;i<V; i++){
        matrix[i] = new int[V];
        for(int j=0; j<V;j++){
            matrix[i][j] =0;
        }
    }
    addEdge(matrix, 0, 1); 
    addEdge(matrix, 0, 4); 
    addEdge(matrix, 1, 2); 
    addEdge(matrix, 1, 3); 
    addEdge(matrix, 1, 4); 
    addEdge(matrix, 2, 3); 
    addEdge(matrix, 3, 4); 
    bool* visited = new bool[V]{0};
    isConnectedDFS(matrix, V, 0, visited); 
    bool done=true;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            done=false;
        }
    }
    cout<<boolalpha<<done<<endl;
}