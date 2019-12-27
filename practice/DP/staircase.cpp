#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n+1] = {0};

    arr[0] =1;
    arr[1] =1;

    for(int i=2;i<=n;i++){
        if(!(i-1<0)){
            arr[i] += arr[i-1];
        }
        if(!(i-2<0)){
            arr[i] +=arr[i-2];
        }
        if(!(i-3<0)){
            arr[i] +=arr[i-3];
        
        }

    }
    cout<<arr[n]<<endl;
}