#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void get_dfs(int **adj_list, int n, int st, bool *visited){
    visited[st] = true;
    for(int i=1; i<n+1; i++){
        if(adj_list[st][i]==1 && !visited[i]){
            visited[i] = true;
            get_dfs(adj_list, n, i, visited);
        }
    }
}

void get_connected(int **adj_list, int n, int &connected){

    bool *visited= new bool[n+1]{false};
    for(int i=1; i<n; i++){
        if(!visited[i]){
            connected = connected + 1;
            get_dfs(adj_list, n, i, visited);
        }
    }
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    int **adj_list = new int*[n+1];
    for(int i=0; i<n+1; i++){
        adj_list[i] = new int[n+1]{0};
    }
    int* u = new int[m];
    int* v = new int[m];

    for(int i=0;i<m;i++){
        int s;
        cin>>s;
        u[i]=s;
    }
    for(int i=0;i<m;i++){
        int s;
        cin>>s;
        v[i]=s;
    }
    for(int i=0; i<m;i++){
        adj_list[u[i]][v[i]]=1;
        adj_list[v[i]][u[i]]=1;
    }

    int connected=0;
    
    get_connected(adj_list, n, connected);
    cout << connected <<endl;
}