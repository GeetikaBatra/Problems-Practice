#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll saveEnergy(ll *arr, ll n){
    ll i=0;
    ll j=0;
    ll ans=0;
    while(i<n-1){
    j = i+1;
    while(j<n-1){
        if(abs(arr[i])>=abs(arr[j]) && arr[i]>=0){
            break;
        }
        j++;
    }
    ans+=(j-i)*arr[i]+(j*j-i*i)*arr[i]*arr[i];
    i = j;
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    cout<< saveEnergy(arr,n)<< endl;
}
