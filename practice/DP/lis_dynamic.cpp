#include<bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){
    int output[n];
    output[0] = 1;
    for(int i=0;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]<arr[j]){
                continue;
            }
            int possible = output[j] +1;
            if(possible>output[i]){
                output[i]=possible;
            }

        }
    }
    int lis=0;

 for(int i=0;i<n;i++){
     if(output[i]>lis){
         lis=output[i];
     }
     
 }
    //  delete [] output;
    return lis;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<lis(arr, n)<<endl;

    //  delete [] arr;
}