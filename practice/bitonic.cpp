// #include<bits/stdc++.h>
// using namespace std;
// int longestBitonicSubarray(int *arr, int n){
//     int lis[n]={1};
//     int lds[n]={1};

//     for(int i=1;i<n;i++){
//         for(int j=i-1; j>0; j--){
//             if(arr[j]<arr[i]){
//                 lis[i]++;
//             }
//         }
//     }
//     for(int i=n-2; i>=0; i--){
//         for(int j=i+1; j<n; j++){
//             if(arr[i]>arr[j]){
//                 lds[i]++;
//             }
//         }
//     }


//     for(int i=0; i<n;i++){
//         lis[i]=lis[i]+lds[i]-1;
//     }
//     int max=0;

//     for(int i=0; i<n; i++){
//         if(max<lis[i]){
//             max=lis[i];
//         }
//     }

//     return max;
// }

// int main(){
//     int n;
//     // cin>>n;
//     n=20;
//     int arr[n]={549,522,736,494,698,517,617,48,834,541,143,553,432,182,526,223,815,213,423,543};
//     // for(int i=0;i<n;i++){
//     //     cin>>arr[i];
//     // }
//     cout << longestBitonicSubarray(arr,n)<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubarray(int *input, int n){
    int i,j;

    int incr[n]={1};

    for(int i=1; i<n;i++){
        if(input[i]>input[j] && (incr[i]<incr[j]+1)){
            incr[i] = incr[j]+1;
        }
    }
    int decr[n];
    for(int i=0;i<n;i++){
        decr[i] =1;
    }

    for(int i=n-2;i>=0;i--){
        for(j=n-1;j>i;j--){
            if(input[i]>input[j] && (decr[i]<decr[j]+1)){
                decr[i]=decr[j]+1;
            }
        }
    }
    int maxim = incr[0] + decr[0] -1;

    for(int i=0; i<n; i++){
        if(incr[i] + decr[i]-1 >maxim){
            maxim = incr[i] + decr[i]-1;
        }

    }
    return maxim;
}

int main(){
    int n;
    // cin>>n;
    n=20;
    int arr[n]={549,522,736,494,698,517,617,48,834,541,143,553,432,182,526,223,815,213,423,543};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout << longestBitonicSubarray(arr,n)<<endl;
}
