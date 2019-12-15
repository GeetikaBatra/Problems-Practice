#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<ll>());
    ll cost_ = 0;
    for(int i=0;i<n; i++){
        cost_ += (1<<i)*arr[i];
    }

    cout << cost_ << endl;

}