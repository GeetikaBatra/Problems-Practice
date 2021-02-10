#include "/Users/gbatra/ProblemPractice/stdc++.h"
#define ll long long
// #define max(a,b) (a>b ? a : b)
// #define min(a,b) (a<b ? a : b)

using namespace std;

ll leftDP[2][1000004];
ll rightDP[2][1000004];
ll arr[1000004];

void delish(ll *arr,ll n){

    leftDP[0][0] = arr[0];
    leftDP[0][1] = arr[0];
    for(ll i=1; i<n; i++){
        leftDP[0][i] = min(leftDP[0][i-1], 0) + arr[i];
        leftDP[1][i] = max(leftDP[1][i-1], 0) + arr[i];
    }
    rightDP[0][n-1] = arr[n-1];
    rightDP[1][n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--){
        rightDP[0][i] = min(rightDP[0][i+1], 0) + arr[i];
        rightDP[1][i] = max(rightDP[1][i+1], 0) + arr[i];
    }
    ll abs_diff = INT_MIN;

    for(ll i=0; i<n; i++){
        abs_diff = max(abs_diff, max(abs(leftDP[0][i]-rightDP[1][i+1]), abs(leftDP[0][i+1]-rightDP[1][i])));
    }
    printf("%lld", abs_diff);
}

int main(){
    int T;
    cin >>T;
    while(T--){
        ll n; 
        scanf("%lld", n);
        ll *arr = new ll[n];
        for(ll i=0; i<n; i++){
           scanf("%lld", &arr[i]);
        }
        delish(arr, n);
    }
}