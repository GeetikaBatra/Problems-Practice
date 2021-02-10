#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int *lis_(int *arr, int n){
    int *lis = new int[n];
    lis[0]=1;
    for(int i=1; i<n; i++){
        int max = INT_MIN;
        for(int j=i-1; j>=0; j--){
            if(arr[i]>arr[j]){
                if(lis[j]>max){
                    max=lis[j];
                }
            }
        }
        if(max==INT_MAX){
            lis[i] =0;
        }
        else{
            lis[i] = max+1;
        }
    }
    
    return lis;
}

int *lds_(int *arr, int n){
    int *lds = new int[n];
    lds[n-1] =1;
    for(int i=n-2; i>=0; i--){
        int max = INT_MIN;
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                if(lds[j]>max){
                    max = lds[j];
                }
            }
        }
        if(max==INT_MAX){
            lds[i] =0;
        }
        else{
            lds[i] = max+1;
        }
       
    }
   
    return lds;
}

int longest_bitonic_seq(int *arr, int n){
    int max = INT_MIN;
    int *lis = lis_(arr, n);
    int *lds = lds_(arr, n);
    for(int i=0; i<n; i++){
        int temp = lis[i] + lds[i] - 1;
        if(temp>max){
            max=temp;
        }
    }
    return max;
}

int main(){
    int *arr = new int[6]{15 ,20, 20, 6 ,4 ,2};
    cout<<longest_bitonic_seq(arr,6)<<endl;
}
