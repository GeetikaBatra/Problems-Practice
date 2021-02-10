#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

vector<int>* dfs_get_connected(int **adj_list, int v, bool* visited, int sv){
    
}

vector<vector<int>>* get_connected(int **adj_list, int v){
    bool *visited = new bool[v]{false};

}

int main(){
    int v,e;
    cin >>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v;i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<e; i++){
        int s,f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    vector<vector<int>> *result = get_connected(adj_list, v);
    for(int i=0; i<result.size(); i++){
        vector<int> pv = result[i];
        for(int j=0; j<pv.size(); j++){
            cout << pv[j]<<" ";
        }
        cout << endl;
    }
}