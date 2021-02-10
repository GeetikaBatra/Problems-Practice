#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int get_node_min(vector<int> &weight, int v, bool *visited){
    int min =INT_MAX;
    int node = -1;
    for(int i=0; i<v;i++){
        if(weight[i]<min && !visited[i]){
            min = weight[i];
            node = i;
        }
    }
    return node;
}
void prims(int **graph, vector<int> &parent, int v){
    
    vector<int> weight;
    weight.push_back(-1);
    for(int i=1; i<v; i++){
      weight.push_back(INT_MAX);
    }
    bool *visited = new bool[v]{0};
    // bool unvisited = new bool[v]{1};
    int count=0;

    
    while(count<v-1){
        int primeV = get_node_min(weight, v, visited);
        cout <<primeV <<endl;
        for(int i=0; i<v; i++){
            
           if(graph[primeV][i]>-1 && graph[primeV][i]<weight[i] && !visited[i]){
               weight[i] = graph[primeV][i];
               parent[i] = primeV;
               
           }
        }
        count++;
        visited[primeV]=1;
        cout<<"newcount"<<count<<endl;
    }
}
int main(){
    int v, e;
    cin>>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v; i++){
        adj_list[i] = new int[v];
        for(int j=0; j<v;j++){
            adj_list[i][j] = -1;
        }
    }   
    
    for(int i=0; i<e;i++){
    int sv, ev, w;
    cin >>sv>> ev>>w;
    adj_list[sv][ev]=w;
    adj_list[ev][sv]=w;
    }
    
    cout <<"gere"<<endl;
    vector<int> parent;
    parent.push_back(0);
    
    prims(adj_list,parent, v);
    for(int i=0; i<v; i++){
        cout<<i<<":"<< parent[i]<<endl;
    }
}