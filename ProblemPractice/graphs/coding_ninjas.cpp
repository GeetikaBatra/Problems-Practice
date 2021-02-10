#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

struct check_obj{
    bool check;
    vector<pair<int,int>> options;
    bool complete = false;
};

void check_neigh(vector<string> &graph, int n, int m, int st, string test_string, bool **visited, int &row, int &col, check_obj &ch){
        // check_obj ch = new check_obj();
        ch.check=false;

        if(row-1>=0 && col-1>=0){
            if(graph[row-1][col-1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row-1, col-1));
            }
        }
        if(col-1>=0){
            if(graph[row][col-1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row, col-1));
            }
        }
        if(row+1!=n && col-1>=0){
            if(graph[row+1][col-1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row+1, col-1));
            }
        }
        if(row+1!=n && col+1!=m){
            if(graph[row+1][col+1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row+1, col+1));
            }
        }
        if(row+1!=n){
            if(graph[row+1][col]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row+1, col));
            }
        }
        if(col+1!=m){
            if(graph[row][col+1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row, col+1));
            }
        }
        if(row-1>=0 && col+1!=m){
            if(graph[row-1][col+1]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row-1, col+1));
            }
        }
        if(row-1>=0){
            if(graph[row-1][col]==test_string[st+1]){
                ch.check = true;
                ch.options.push_back(make_pair(row-1, col));
            }
        }

        if(ch.check && (st+1==test_string.length()-1)){
            ch.complete=true;
        }
}

bool coding_ninjas_helper(vector<string> &graph, int n, int m, int st, string test_string,  bool** visited, int &row, int &col){

    int curr_row=row;
    int curr_col=col;
    check_obj ch;
    check_neigh(graph, n, m, st, test_string,visited, row, col, ch);
    if(ch.check){
        if(ch.complete){
            return true;
        }
        for(int i=0; i<ch.options.size(); i++){
            visited[curr_row][curr_col] = true;
            
            bool res = coding_ninjas_helper(graph, n, m, st+1, test_string, visited, ch.options[i].first, ch.options[i].second);
            if(res){
                return true;
            }
            visited[curr_row][curr_col]=false;
        }
    }
    return false;
}

bool coding_ninjas(vector<string> &graph, int n, int m, string test_string){
    
    bool **visited = new bool*[n];
    bool res=false;
    for(int i=0; i<m; i++){
        visited[i] = new bool[m]{false};
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==test_string[0]){
                res=coding_ninjas_helper(graph, n,m,0, test_string, visited, i, j);
                if(res){
                    return res;
                }
            }
        }
    }
    return res;
}

int main(){
    int n, m;
    // cin>>n>>m;
    n=4, m=4;
    vector<string> graph;
    graph.push_back("CANI");
    graph.push_back("OOJN");
    graph.push_back("DDIG");
    graph.push_back("JNIN");
    // graph.push_back("AJNINGNIDOC");
    // graph.push_back("XOXIXGXIXJX");
    // for(int i=0; i<n; i++)
    // {
    //     string s;
    //     cin>>s;
    //     graph.push_back(s);
    // }
    string test_string="CODINGNINJA";
    
    bool res = coding_ninjas(graph, n, m, test_string);
    cout<<res<<endl;
}