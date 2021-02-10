#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int loothouse(int *arr, int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    
    // dp[1] = arr[1];
    for(int i=1; i<=n; i++){
        int ans = max(dp[i], dp[i-1]+arr[i]);
        dp[i+1] = ans;
    }
    // for(int i=0; i<=n; i++){
    //     cout << dp[i] <<endl;   
    // }
    return dp[n+1];
}

int main(){
    int arr[10] = {9583, 8878, 3709, 6449, 6541, 6394, 376, 3126, 5077, 964};
    int n=10;
    cout << loothouse(arr, n) <<endl;
}