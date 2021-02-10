#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

class Graph{
    public:
        int V;
        int *adj_mat;
        Graph(int V);
        void add_edge(int u, int v);
        void print_graph();
};

Graph::Graph(int V){

    this -> V =V;
    adj_mat = new int[V*V];

}

void Graph::add_edge(int u, int v){
    adj_mat[u*this->V+v]=1;
}

void Graph::print_graph(){
    cout<<"The Graph formed is: " << endl;
    for(int i=0; i<this->V; i++){
        for(int j=0; j<this->V; j++){
            cout<<this->adj_mat[i*V+j]<<" ";
        }
        cout << endl;
    }
}
int main(){
    Graph graph(4);
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(2,0);
    graph.add_edge(2,3);
    graph.add_edge(3,3);
    graph.print_graph();
    return 0;
}