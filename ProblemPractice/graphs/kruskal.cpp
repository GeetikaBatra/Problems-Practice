#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
struct edge{
    int sv, ev;
    int w;
};

bool comp(edge e1, edge e2){
    if(e1.w<e2.w){
        return true;
    }
    return false;
}

void print_mst(int **mst, int v){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(mst[i][j]==1){
                cout << i <<":"<<j <<",";
            }
        }
        cout<<endl;
    }
}

bool has_path(int **mst, int sv, int ev, int v, bool *visited){
    
    cout<<":reached has_path"<<endl;
    queue<int> q;
    q.push(sv);
    visited[sv]= true;
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<endl;
        q.pop();
        // visited[temp]=true;
        for(int i=0; i<v; i++){
            cout <<"************"<< i << visited[i]<<endl;
            if(mst[temp][i]==1 && !visited[i]){
                if(i==ev){
                return true;
                }
                q.push(i);
                // visited[i]=true;
            }
        }
    }
    // visited[sv]= true;
    return false;
}

void kruskals(int **mst, vector<edge> &edges, int v){
    // cout<<"insidekruskals"<<endl;
   vector<edge>::iterator it;
   int count=0;
   for(it=edges.begin(); it!=edges.end(); it++){
       cout<<it->sv<<it->ev<<it->w<<endl;
   }
   bool *visited = new bool[v]{0};
   for(it=edges.begin(); it!=edges.end(); it++){
       
       if(!has_path(mst, it->sv, it->ev, v, visited)){
           mst[it->sv][it->ev]=1;
           mst[it->ev][it->sv]=1;
           count++;
           if(count==v){
               break;
           }
       }
   }
   return;
}   

int main(){
    int v, e;
    cin>>v>>e;
    vector<edge> vec;
    for(int i=0; i<e; i++){
        int sv, ev, w;
        cin>>sv>>ev>>w;
        edge e;
        e.sv = sv;
        e.ev = ev;
        e.w = w;
        vec.push_back(e);
    }
    cout<< "reached here"<< endl;

    sort(vec.begin(), vec.end(), comp);
    cout << "******2"<< endl;
    int **mst = new int*[v];
    for(int i=0; i<v; i++){
        mst[i] = new int[v]{0};
    }
    cout << "******3"<< endl;
    kruskals(mst, vec, v);
    print_mst(mst, v);
}