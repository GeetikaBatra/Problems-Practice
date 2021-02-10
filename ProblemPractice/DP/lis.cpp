#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int lis(int *arr, int n){
    int *op = new int[n];
    op[0]=1;
    for(int i=1; i<n; i++){
        int  max = INT_MIN;
        for(int j=i-1; j>=0; j--){
            if(arr[j]<arr[i]){
                if(op[j]>max){
                    max = op[j];
                }
            }
        }
        op[i] = max+1;
    }
    return op[n-1];
}

int main(){
    int *arr = new int[9]{10,22,9,33,21,50,41,60,80};
    cout<<lis(arr, 9)<<endl;
}