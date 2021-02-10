#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        map<int,int> m;
        for(int j=0; j<n; j++){
            int item;
            cin >> item;
            if(!m[item]){
                m[item]=1;
            }
            m[item]++;
        }
        
    }
}