#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void bfs(int **adj_list, int v, bool *visited, int st, vector<int> &sub_vec){
        queue<int> q;
        visited[st]  = true;
        sub_vec.push_back(st);
        q.push(st);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0; i<v;i++)
            {   
                if(adj_list[temp][i]==1 && !visited[i]){
                    q.push(i);
                    sub_vec.push_back(i);
                    visited[i] = true;
                }
            }
        }
        sort(sub_vec.begin(), sub_vec.end());
}

void get_conn_bfs(int **adj_list, int v, vector<vector<int>> &res){
    bool *visited = new bool[v]{false};
    
    for(int i=0; i<v; i++){
        
        if(!visited[i]){
            vector<int> sub_vec;
            bfs(adj_list, v, visited, i, sub_vec);
            res.push_back(sub_vec);
            sub_vec.clear();
        }
        
    }
}

int main(){
    int v, e;
    cin >>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v; i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s, f;
        cin >>s>>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
       
    }
     vector<vector<int>> res;
    get_conn_bfs(adj_list, v, res);
    for(int i=0; i<res.size(); i++){
        vector<int> temp = res[i];
        
        for(int j=0; j<temp.size(); j++){
            cout <<temp[j]<<" ";
        }
        cout << endl;
    }
}