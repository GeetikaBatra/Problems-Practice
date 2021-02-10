#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;


int main(){
    int v, e;
    cin >>v>>e;
    int **adj_list = new int*[v];
    for(int i=0; i<v; i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0; i<v; i++){
        int s,f;
        cin>>s>>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }
    vector<int>* result = getConnect(int **adj_list, int v);
    for(int i=0; i<v; i++){
        
    } 
}