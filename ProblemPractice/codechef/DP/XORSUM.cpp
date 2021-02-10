#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// int main(){
//     // int arr[3] = {1,2,3};
//     int T;
//     cin >> T;
//     while(T--){
//         int n,k;
//         cin>>n>>k;
//         int *arr = new int[n];
//         for(int i=0; i<n; i++){
//             cin >>arr[i];
//         }
//         int DP[10004][10004];
//         DP[0][0] = 0;
//    int n_sofar = 1;
//    int max_xor =INT_MIN;
   
//    while(true){
//        if(n_sofar==(1<<n)){
//            break;
//        }
//        for(int i=0; i<n_sofar; i++){
//            DP[i+n_sofar][0] = DP[i][0] ^ arr[0];
//            max_xor = max(max_xor, DP[i+n_sofar][0]);
//        }
//        n_sofar = 2*n_sofar;
//        arr=arr+1;
//    }
//    for(int i=0; i<n_sofar; i++){
//            max_xor = max(max_xor, max(DP[i][0], k^DP[i][0]));
//        }
//         cout <<max_xor<<endl;
//     }
    
// }

// int xorSum(int *arr, int n, int k){
    
//     return max_so_far;
// }

int main(){
    
    int T;
    cin >>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

    int DP[1004] ;
    DP[0] = 0;
    int n_sofar =1;
    while(n_sofar!=(1<<n)){
        for(int i=0; i<n_sofar; i++){
            DP[i+n_sofar] = DP[i]^arr[0];
        }
        n_sofar = 2*n_sofar;
        arr= arr+1;
    }
    int max_so_far = INT_MIN;
    for(int i=0; i<n_sofar; i++){
        max_so_far = max(max_so_far, max(DP[i],  DP[i]^k));
    }

    
        cout <<  max_so_far<< endl;
    }
   
}