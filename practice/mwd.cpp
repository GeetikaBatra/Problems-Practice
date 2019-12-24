#include<bits?stdc++.h>
using namespace std;
struct pair{
    int n1, n2;
}
pair chefStones(int n1, int n2, int m){
    for(int(i=0;i<m;i++){
        if((n1-i)<1 || (n2-i)<1){
            break;
        }

        n1=n1-i;
        n2=n2-i;
    }
    pair p = {n1,n2};
    return p
}
int main(){
    int T;
    cin>>T;
    vector<pair> res;
    for(int i=0;i<T;i++){
        int n1, n2, m;

        cin>>n1>>n2>>m;
        res.push_back(chefStones(n1,n2,m));
    }
    for(int i=0;i<T;i++){
        cout<< res[i].n1 + res[i].n2<< endl;
    }
}