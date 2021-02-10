#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void Dijikstras(int **graph, int v, int ev){

    bool *visited = new bool[v]{0};
    int *dist = new int[v];

    dist[0] =0;

    for(int i=1; i<v; i++){
        dist[i] = INT_MAX;
    }

    for(int i=0; i<v; i++){
        visited[i] =1;
        for(int j=0; j<v; j++){
           if(graph[i][j]>-1 && !visited[j]){
            if((dist[i] + graph[i][j]) < dist[j]){
                dist[j] = dist[i] + graph[i][j];
            }
           }
        }
    }   
    cout << dist[ev]<<endl;
}

int main(){
    int v,e;
    cin >>v>>e;
    int **graph = new int*[v];
    for(int i=0; i<v; i++){
        graph[i] = new int[v];
    }
    for(int i=0; i<v;i++){
        for(int j=0; j<v; j++){
            graph[i][j] = -1;
        }
    }
    for(int i=0; i<e; i++){
        int s, f, w;
        cin>>s>>f>>w;
        graph[s][f] =w;
        graph[f][s] =w;
    }
    Dijikstras(graph, v, 2);
}