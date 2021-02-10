#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

bool isConnectedBFS(int **adj_list, int v){
    bool *visited = new bool[v]{false};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        visited[temp] = true;
        for(int i=0; i<v; i++){
            if(adj_list[temp][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for(int i=0; i<v; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int v,e;
    cin>>v>>e;
    int **adj_list= new int*[v];
    for(int i=0;i<v;i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e;i++){
        int s,f;
        cin>>s>>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    cout<<boolalpha<<isConnectedBFS(adj_list, v);

}