// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int get_codes3(int *arr, int n){
//     //iterative + dynamic
//     int output[n+1]= {0};
//     output[0]=1;
//     output[1]=1;
//     for(int i=2; i<=n; i++){
//         output[i] = output[i-1];
//         if((arr[i-2]*10+arr[i-1])<=26){
//             output[i]+=output[i-2];
//         }
//     }
//     return output[n];
// }
// int get_codes2(int *arr, int n, int *output){
//     //recursive + dynamic
//     if(n==0){
//         return 1;
//     }
//     if(n==1){
//         return 1;
//     }
//     if(output[n]>0){
//         return output[n];
//     }
//     // for(int i=0;i<n;i++){
//     //     cout << output[i];
//     // }
//     int curr_count = get_codes2(arr, n-1, output);

//     if((arr[n-2]*10+arr[n-1])<=26){
//         curr_count+=get_codes2(arr,n-2, output);
//     }
//     output[n] = curr_count;
    
//     return curr_count;
// }
// // int get_codes(int *arr, int n){
// //     //recursive from begining
// //     if(n=0){
// //         return 1;
// //     }
// //     if(n=1){
// //         return 1;
// //     }
// //     int output = get_codes(arr+1, n-1);
// //     if((arr[0] + arr[1])<26){
// //         output+=get_codes(arr+2,  n-2);
// //     }
// //     return output;
// // }
// // int get_codes(int *arr, int n){
// //     //Recursive method from end;
// //     if(n==0){
// //         return 1;
// //     }
// //     if(n==1){
// //         return 1;
// //     }
// //     int output = get_codes(arr, n-1);
// //     if((arr[n-2]*10+arr[n-1])<=26){
// //         output+=get_codes(arr,n-2);
// //     }
// //     return output;
// // }

// int main(){
//     string num;
//     cin>>num;
//     int n = num.length();
//     int arr[n];
//     for(int i=0;i<n;i++){
//         int digit=(int)num[i]-(int)48;
//         arr[i]=digit; 
//     }
//     // int output[n]={0};
//     cout << get_codes3(arr, n)<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int get_codes(int *arr, int n){
    //iterative + dynamic
    int output[n+1]= {0};
    output[0]=1;
    output[1]=1;
    for(int i=2; i<=n; i++){
        output[i]=output[i-1];
        if((arr[i-2]*10+arr[i-1])<=26){
            output[i]+=output[i-2];
        }
    }
    return output[n];
}

int main(){

    while(true){
    string num;
    cin>>num;
    int n = num.length();
    if (num.length()==1){
        if(((int)num[0]-(int)48)==0){
            break;
        }
    }
    int arr[n];
    for(int i=0;i<n;i++){
        int digit=(int)num[i]-(int)48;
        arr[i]=digit; 
    }
    // int output[n]={0};
    cout << get_codes(arr, n)<<endl;

     }
}
