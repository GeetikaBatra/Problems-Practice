#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void print_DFS(int **adj_list, int v, int src, bool *visited){
    cout << src << " ";
    visited[src] = true;
    for(int i=0; i<v; i++){
        if(i==src){
            continue;
        }
        if(adj_list[src][i]==1){
            if(!visited[i]){
                print_DFS(adj_list, v, i, visited);
            }
        }
    }
}
void DFS(int **adj_list, int v){
    bool *visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    for(int i=0; i<v; i++){
        if(!visited[i]){
            print_DFS(adj_list, v, i, visited);
        }
    }
    cout << endl;
}
void print_BFS(int **adj_list, int v, int src, bool *visited){
    queue<int> q;
    q.push(src);
    visited[src] = true;    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(int i=0; i<v; i++){
            if(i==temp){
                continue;
            }
            if(adj_list[temp][i]==1){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}
void BFS(int **adj_list, int v){
    bool *visited = new bool[v];
    
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    for(int i=0; i<v;i++){
        if(!visited[i]){
            print_BFS(adj_list, v, i, visited);
        }
    }
    cout << endl;

    delete [] visited;
}
int main(){
    int v, e;
    cin >>v>>e;
    int **adj_list = new int*[v];
    for(int i=0;i<v; i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s, f;
        cin >> s >>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    
    // (DFS(adj_list,v);
    BFS(adj_list,v);

    // for(int i=0; i<v; i++){
    //     delete [] adj_list
    // }
}