#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

struct Edge{
    int sv;
    int ev;
    int w;
};

bool compare(Edge e1, Edge e2){
    return e1.w<e2.w;
}

int getParent(int p, int v, vector<int>& parent ){
    if(p==v){
        return p;
    }
    return getParent(parent[v], v, parent);
}

void kruskals(vector<Edge> &edges, int v, vector<Edge> &output){
    sort(edges.begin(), edges.end(), compare);
    int count=0;
    int i=0;
    vector<int> parent;
    for(int i=0; i<v; i++){
        parent.push_back(i);
    }
    
    while(count<v-1){
        Edge e = edges[i];
        int p1 = getParent(parent[e.sv], e.sv, parent);
        int p2 = getParent(parent[e.ev], e.ev, parent);
        if(p1!=p2){
            count++;
            parent[p1] = p2;
            output.push_back(e);
        }
        i++;
    }
}

int main(){
    int v, e;
    cin >>v>>e;
    vector<Edge> edges; 
    for(int i=0; i<e; i++){
        int sv, ev, w;
        cin >> sv >> ev >> w;
        Edge e;
        e.sv = sv;
        e.ev = ev;
        e.w =w;
        edges.push_back(e);
    }
    cout << "Reched main"<<endl;
    vector<Edge> output;
    kruskals(edges, v,output);
    for(int i=0; i<v-1; i++){
        cout << output[i].sv << " "<< output[i].ev << " " << endl;
    }

}

