#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

vector<int>* get_path_bfs(int** adj_list, int v, int sv, int ev){
    queue<int> q;
    bool *visited = new bool[v]{false};
    unordered_map<int, int> m;
    q.push(sv);
    visited[sv] = true;
    bool done=false;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i<v; i++){
            if(i==temp){
                continue;
            }
            if(adj_list[temp][i] && !visited[i]){
                q.push(i);
                visited[i]= true;
                m[i]=temp;
                if(i==ev){
                    done=true;
                    break;
                }
            }
        }
        if(done){
            break;
        }
    }
    if(!done){
        return NULL;
    }
    vector<int>* res= new vector<int>();
    int temp=ev;
    while(temp!=sv){
        res->push_back(temp);
        temp=m[temp];
    }
    res->push_back(sv);
    
    return res;
}

int main(){
    int v,e;
    cin>>v>>e;
    int **adj_list = new int*[v];
    for(int i=0;i<v;i++){
        adj_list[i] = new int[v]{0};
    }
    for(int i=0;i<e;i++){
        int s,f;
        cin>>s>>f;
        adj_list[s][f]=1;
        adj_list[f][s]=1;
    }

    int sv,ev;
    cin>>sv>>ev;
    //cout <<" here";
    vector<int>* result = get_path_bfs(adj_list, v, sv, ev);
    if(result!=NULL)
    {
        for(int i=0;i<result->size(); i++){
        cout << result->at(i)<<endl;
     }
    }
    
}