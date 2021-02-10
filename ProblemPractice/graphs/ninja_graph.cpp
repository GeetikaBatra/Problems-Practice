#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void print_graph(int **arr, int n, bool *visited, int src){
    //DFS 
    cout<<src<<endl;
    visited[src] = true;
    for(int i=0; i<n; i++){
        if(arr[src][i]){
            if(!visited[i]){
            print_graph(arr, n, visited, i);
         }
        }
    }
    return;
}
void bfs_helper(int **arr, int n, bool *visited, int src, queue<int> &q){
        while(!q.empty()){
        int node = q.front();
        cout<< node<< endl;
        for(int i=0;i<n;i++){
            if(arr[node][i]==1 &&!visited[i]){
            q.push(i);
            visited[i] = true;
            }
        }
        q.pop();
    }
}
void print_graph_bfs(int **arr, int n, bool *visited, int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    bfs_helper(arr, n, visited, src, q);
    int i=0;
    while(true){
        if(!visited[i] && i<n){
            q.push(i);
            visited[i] = true;
            bfs_helper(arr,n,visited, i, q);
            i++;
        }
        if(i==n){
            break;
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int **arr = new int*[v];
    for(int i=0;i<v;i++){
        arr[i]= new int[v]{0};
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;  
        arr[f][s]=1;
        arr[s][f]=1;
    }
    bool *visited = new bool[v]{0};
    // print_graph(arr, v, visited, 0);
    print_graph_bfs(arr, v, visited, 0);  
}