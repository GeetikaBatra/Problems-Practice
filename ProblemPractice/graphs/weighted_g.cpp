#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

template <typename T>
// template <typename U>
class Graph{
    map<T, pair<T,int> > graphMap;
public:
    Graph(){}
    void addEdge(T u, T v, bool bidir, int weight){
        graphMap[u].push_back(pair(v,weight));
        if(bidir){
            graphMap[v].push_back(pair(u, weight));
        }
    }
    void printGraph(){
        for(auto row: graphMap){
            cout<<row.first<<"->";
            for(auto col: row.second){
                cout<<col.first<<"("<<col.second<<");";
            }
            cout << endl;
        }
    }
};
int main(){
    Graph<string,int> g;
    g.addEdge("Amritsar", " Delhi", 1);
    g.addEdge("Delhi", " Mumbai", 2);
    g.addEdge("Mumbai", "Kolkata", 3);
    g.addEdge("Kolkata", "Hydrabad", 5);
    g.addEdge("Delhi", "Kolkata", 4);
    g.printGraph();
}