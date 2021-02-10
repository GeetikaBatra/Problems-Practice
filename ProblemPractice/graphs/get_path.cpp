#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

vector<int>* get_path_dfs(int **adj_list, int v, int start, int end, bool *visited){
    vector<int>* res = new vector<int>();
    if(start==end){
        res->push_back(end);
        visited[end] = true;
        return res;
    }
    visited[start]=true;
    for(int i=0; i<v; i++){
        if(adj_list[start][i]==1 && !visited[i]){
            // visited[i] = true;
            res = get_path_dfs(adj_list, v, i, end, visited);
            if(res!=NULL){
                res->push_back(start);
            }
            return res;
        }
    }
    return NULL;
}

int main(){
    int v,e;
    cin >> v >>e;
    int **adj_list = new int*[v];
    for(int i=0;i<v;i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s,f;
        cin >>s >>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    int start,end;
    cin>>start>>end;
    vector<int> node_list;
    bool *visited = new bool(v);
    vector<int>* result =  get_path_dfs(adj_list, v, start, end, visited);
    if(result!=NULL){
        for(int i=0; i<result->size();i++){
            cout << result->at(i)<< endl;
        }
    }
    for(int i=0; i<v; i++){
        delete [] adj_list[i];
    }
    delete[] adj_list;
    delete [] result;
    
}