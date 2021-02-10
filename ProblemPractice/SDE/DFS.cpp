#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void addEdge(int **matrix, int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void DFS(int **arr, int V, bool *visited, int src){
    //DFS 
    cout<<src<<endl;
    visited[src] = true;
    for(int i=0; i<V; i++){
        if(arr[src][i]){
            if(!visited[i]){
            DFS(arr, V, visited, i);
         }
        }
    }
    return;
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
    bool visited[V];
    DFS(matrix, V, visited, 0); 
}