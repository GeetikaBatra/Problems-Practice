#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int alpha_code_dp(int *arr, int n, int *op){
    if(n==0){
        op[0]=1;
    }
    if(n==1){
        op[1]=1;    
    }
    if(op[n]){
        return op[n];
    }
    int ret;
    ret = alpha_code_dp(arr, n-1, op);
    if(arr[n-2]*10 + arr[n-1]<=26){
        ret += alpha_code_dp(arr, n-2, op);
    }
    op[n] = ret;
    return ret;
}

int alpha_code_for_dp(int *arr, int n){
    int *op = new int[n+1];
    op[0]=1;
    op[1] = 1;
    for(int i=2; i<n+1; i++){
        op[i] = op[i-1];
        if(arr[i-2]*10 + arr[i-1]<=26){
            op[i] += op[i-2];
        }
    }
    return op[n];
}

int alphacode_rec(int *arr, int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 1;
    }
    int out = alphacode_rec(arr, n-1);
    if((arr[n-1]*10+arr[n])<26){
        out=out + alphacode_rec(arr, n-2);
    }
    return out;
}

int main(){
    int n=3;
    int *arr = new int[3];
    for(int i=0; i<n;i++){
        arr[i] =i+1;
    }
    int *op = new int[3+1]{0};
    
    cout <<alpha_code_dp(arr, 3, op)<<endl;
    cout<<alphacode_rec(arr, 3)<<endl;
    cout<<alpha_code_for_dp(arr,3)<<endl;
}