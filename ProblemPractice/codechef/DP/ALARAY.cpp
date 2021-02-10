#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void check_alt_array(int *arr, int n){
    int *new_arr = new int[n];
    new_arr[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]* (long long)arr[i+1]<0){
            new_arr[i] = new_arr[i+1] +1;
        }
        else{
            new_arr[i] = 1;
        }
    }
    for(int i=0; i<n; i++){
       cout << new_arr[i] << "  ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        check_alt_array(arr, n);
    }
}