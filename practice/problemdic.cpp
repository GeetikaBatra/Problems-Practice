#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>());
    int i=0;
    int j=n-1;
    
    while(true){
        if(i==j){
            arr[i] = arr[i]-k;
            break;
        }
        arr[i] = arr[i]-k;
        arr[j] = arr[j]+k;
        i++;
        j--;
    }
    
    sort(arr, arr+n, greater<int>());
    cout << (arr[0]-arr[n-1])<<endl;

}