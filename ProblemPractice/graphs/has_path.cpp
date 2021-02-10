#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

bool has_path_dfs(int **adj_list, int v, int start, int end, bool *visited){
   
    if(start==end){
        return true;
    }
    visited[start] = true;
    for(int i=0; i<v; i++){
        if(adj_list[start][i]==1 && !visited[i]){
            bool result = has_path_dfs(adj_list, v, i, end, visited);
            // visited[i]= true;
            if(result){
                return true;
            }
        }
    }
    return false;
}

bool has_path_bfs(int **adj_list, int v, int start, int end){
    queue<int> q;
    q.push(start);
    bool *visited = new bool[v]{false};
    // for(int i=0; i<v; i++){
    //     visited[i] = false;
    // }
    visited[start] = true;
    while(!q.empty()){
        int temp = q.front();
        if(temp==end){
            return true;
        }
        q.pop();
        for(int i=0; i<v; i++){
            if(adj_list[temp][i]==1 && !visited[i]){
                q.push(i);
                visited[i] =true;
            }
        }
    }
    return false;
}
int main(){
    int v, e;
    cin>>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v; i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s,f;
        cin >>s>>f;
        adj_list[s][f] = 1;
        adj_list[f][s] = 1;
    }
    int start, end;
    cin>>start>>end;
    bool *visited = new bool[v]{false};
    // cout << boolalpha<<has_path_bfs(adj_list,v, start, end)<<endl;
    cout << boolalpha<<has_path_dfs(adj_list, v, start, end, visited)<<endl;
}