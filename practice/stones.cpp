#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll T;
    cin>>T;
    vector<ll> res;
    for(ll i=0;i<T;i++){
        ll n1, n2, m;

        cin>>n1>>n2>>m;
        ll x = min(m*(m+1)/2, min(n1,n2));

        res.push_back(n1+n2-2*x);
    }
    for(ll i=0;i<T;i++){
        cout<<res[i]<<endl;
    }
}
