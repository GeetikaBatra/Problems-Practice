#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// void connectedComponents(unordered_map<int, vector<int>*> &adj_list, unordered_map<int, bool>)
void get_dfs_comp(int **adj_list, int v, int st, bool *visited, vector<int> &temp){

    if(!visited[st]){
        temp.push_back(st);
    }
    visited[st] = true;
    // cout<<"V"<<v<<endl;
    for(int i=0; i<v; i++){
    
        if(adj_list[st][i]==1 && !visited[i]){
            temp.push_back(i);
        
            visited[i] = true;
            get_dfs_comp(adj_list,v,i,visited,temp);
        }
    }
    
    return;
}
void get_all_connect(int **adj_list, int v, vector<vector<int>> &res){
    bool *visited = new bool[v]{false};

    for(int i=0; i<v; i++){
        if(!visited[i]){
            vector<int> temp;
            get_dfs_comp(adj_list, v, i, visited, temp);
            // cout<<"reahed here"<<endl;
            res.push_back(temp);
        }
    }
}
int main(){
    int v, e;
    cin>>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v; i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s, f;
        cin >>s>>f;
        adj_list[s][f] = 1;
        adj_list[f][s] = 1; 
    }
    vector<vector<int>> res;
    get_all_connect(adj_list, v, res);
    for(int i=0; i<res.size(); i++){
        vector<int> temp = res[i];
        for(int j=0; j<temp.size(); j++){
            cout << temp[j]<< " ";
        }
        cout <<endl;
    }
    for(int i=0;i<res.size(); i++){
       res[i].clear();
    }
    res.clear();
}
