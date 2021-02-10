#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

long long DP[100004][10004];

void minCoinChange(int *arr, int n, int k){
    for(int i=0; i<=n; i++){
        DP[i][0] = 1;
    }
    for(int i=1;i<=k; i++){
        DP[0][i] = INT_MAX;
    }
    for(int i=1;i<=n; i++){
        for(int j=1; j<=k; j++){
            long long k_behind =INT_MAX;
            if(j>=arr[i-1]){
                k_behind = DP[i][j-arr[i-1]];
            }
            DP[i][j] = min(1+k_behind, DP[i-1][j]);
        }
    }
    for(int i=0; i<=n ; i++){
        for(int j=0; j<=k; j++){
            cout << DP[i][j]<< " ";
        }
        cout << endl;
    }
    cout << DP[n][k]<<endl;
}

int main(){
    int arr[2] = {1,5};
    minCoinChange(arr, 2, 6);
}
