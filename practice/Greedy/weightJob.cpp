#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Job{
    int start, finish, weight;
};
bool compare(Job j1, Job j2){
   return (j1.finish<j2.finish); 
}
int findMaxProfit(Job *jobs, int n){
    int dp[n] = {0};
    sort(jobs, jobs+n, compare);
    // for(int i=0; i<n; i++){
    //     cout << jobs[i].start << jobs[i].finish << jobs[i].weight << endl;
    // }
    dp[0] = jobs[0].weight;
    for(int i=1;i<n;i++){
        int including = jobs[i].weight;
        int conflict=-1;
        // cout<< including << endl;
        for(int j=i-1; j>=0; j--){
            if(jobs[j].finish<=jobs[i].start){
                conflict=j;
                break;
            }
        }
        if(conflict!=-1){
            including += dp[conflict];
        }
        cout << dp[i] << endl;
        dp[i] = max(including, dp[i-1]);
        cout<<dp[i]<<endl;
    }
    int ans = dp[n-1];
    // delete[] dp;
    return ans;
}

int main(){
    // int n=8;
    // int n=4;
    // Job jobs[n] = {{3,10,20},{1,2,50},{6,19,100},{2,100,200}};
    cin >> n;
    // Job jobs[n] = {{5786,8113,5087},{8765,19303,9710}, {3455,5829,2447}, {2637,10599,8208},
    // {3913,11083,7236}, {4652,14046,1486},{1778,6621,3585},{807,10139,8713}};
        for(int i=0; i<n; i++){
            Job J;
            cin>> J.start >> J.finish >> J.weight;
            jobs[i] = J;
        }
    cout<<findMaxProfit(jobs, n)<<endl;
}

// #include<bits/stdc++.h>
// using namespace