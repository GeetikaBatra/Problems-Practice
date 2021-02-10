//https://www.codechef.com/problems/ADADISH

#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
// Pair wise is not getting accepted
// void adaish(int *arr, int n){
//     sort(arr, arr+n);
//     int t_sum =0;
//     for(int i=0; i<n; i++){

//         t_sum +=arr[i];
//     }
//     int min_sum = INT_MAX;
//     for(int i=0; i<n-1; i++){
//         int pair_sum = arr[i] + arr[i+1];
//         if(pair_sum>=t_sum-pair_sum){
//             min_sum = min(min_sum, pair_sum);
//         }
//     }
//     cout << min_sum<<endl;
// }

// The idea is to sort in decreasing order use the max time taking objects. Simple sa funda hai, max wale pehle utilize kar lo
//So that jab min bach jae to add hoke jada value na banae. Agar min walo ko burner pe lagaenge while ek max khatam hota hai.
// This will not be a min value as 4 ke bad 3 bachta hai to 4+3 > 4+1 if we have (1,3,4).
// int arr[1004];
// void adadish(int *arr, int n){
//     sort(arr, arr+n);
//     int b1 = 0;
//     int b2 = 0;
//     for(int i=n-1; i>=0; i--){
//         if(b1<b2){
//             b1+=arr[i];
//         }
//         else{
//             b2+=arr[i];
//         }
//     }
//     cout << max(b1,b2);
// }

// int main(){
//     int T;
//     cin >>T;
//     while(T--){
//         int n;
//         cin >>n;
//         int *arr = new int[n+1];
//         for(int i=0;i<n; i++){
//             cin >> arr[i];
//         }
//         adadish(arr,n);
//     }
// }
//https://www.codechef.com/problems/ADADISH



int arr[10004];
int main(){
    int T;
    cin >>T;
    while(T--){
        int n;
        cin >>n;
        for(int i=0;i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
    int b1 = 0;
    int b2 = 0;
    for(int i=n-1; i>=0; i--){
        if(b1<=b2){
            b1+=arr[i];
        }
        else{
            b2+=arr[i];
        }
    }
    cout << max(b1,b2)<<endl;

    }
    return 0;
}

