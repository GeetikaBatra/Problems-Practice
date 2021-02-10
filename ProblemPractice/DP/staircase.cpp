#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int staircase_rec(int n, int* op){
    if(op[n]!=-1){
        return op[n];
    }
    if(n==0){
        op[n] =0;
        return 0;
    }
    if(n==1){
        op[n]=1;
        staircase_rec(n-1, op);
        return 1;
    }
    if(n==2){
        op[n]=2;
        staircase_rec(n-1, op);
        return 2;
    }

    int res = staircase_rec(n-1, op) + staircase_rec(n-2, op) + staircase_rec(n-3, op);
    op[n] = res;
    return res;
}

int main(){
    int *op = new int[5];
    for(int i=0; i<5; i++){
        op[i] =-1;
    }
    cout<<staircase_rec(4, op)<<endl;
}