#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int print_arr(int n, int *arr){
    if(n<0){
        return 0;
    }
    return print_arr(n-1, arr) + arr[n];
}

int main(){
    int n=3;
    int arr[3] = {9, 6, 9};
    cout << print_arr(n-1, arr) << endl;
}