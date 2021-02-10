#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void addEdge(int **matrix, int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}
void printGraph(int **matrix, int v){
    for(int i=0; i<v; i++){
        for(int j=0;j<v; j++){
            cout << matrix[i][j];
        }
        cout << endl;
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
    printGraph(matrix, V); 
}