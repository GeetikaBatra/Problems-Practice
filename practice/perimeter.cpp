#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << endl;
    // }
    int curr =-1;
    for(int i=0; i<n-2; i++){
        if(arr[i+1]+arr[i+2]>arr[i]){
            curr =i;
            break;
        }
    }
    if(curr!=-1){
        cout << arr[curr+2]<< " " << arr[curr+1] << " "<< arr[curr]  << endl;
        return 0;
    }
    cout << -1 << endl;
}