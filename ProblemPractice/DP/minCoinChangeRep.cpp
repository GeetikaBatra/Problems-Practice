#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int DP[100004][10004];

int minCoinChange(int *arr, int n, int k){
    
    for(int i=0; i<=k; i++){
        DP[0][i] = INT_MAX-1;
    }
    for(int i=1; i<=n;i++){
        DP[i][0] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            int k_before = INT_MAX-1;
            if((j-arr[i-1])>=0){
                k_before = DP[i][j-arr[i-1]];
            }
            DP[i][j] = min((1+k_before), DP[i-1][j]);
        }
    }
    return DP[n][k];
}

int main(){
    int arr[3] = {25,10,5};
    cout << minCoinChange(arr, 3, 30) <<endl;
}