#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int DP[10004][10004];

void dboy(int n, int *H, int *K){

    int max_h = 0;
    for(int i=0;i<n; i++){
        max_h = max(max_h, H[i]);
    }
    for(int i=0; i<=(2*max_h); i++){
        DP[0][i] = INT_MAX-1;
    }
    for(int i=1; i<=n; i++){
        DP[i][0] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(2*max_h); j++){
            int prev_data = INT_MAX-1;
            if(j-K[i-1]>=0){
                prev_data = DP[i][j-K[i-1]];
            }
            DP[i][j] = min(1+ prev_data, DP[i-1][j]);
        }
    }
    int min_rounds = 0;
    for(int i=0; i<n; i++){
        min_rounds += DP[n][2*H[i]];
    }
    cout<<min_rounds<<endl;
}
int main(){

    int T;
    cin >>T;
    while(T--){
        int n ;
        cin>>n;
        int *H = new int[n];
        int *K = new int[n];
        for(int i=0; i<n;i++){
            cin>>H[i];
        }
         for(int i=0; i<n;i++){
            cin>>K[i];
        }
        dboy(n, H, K);

    }
}