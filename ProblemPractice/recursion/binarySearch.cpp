#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int binarySearch(int si, int ei, int item,int* arr){
    if(ei<si){
        return -1;
    }
    int mid = (ei+si)/2;
    if(item==arr[mid]){
        return mid;
    }
    if(item<arr[mid]){
        return binarySearch(si, mid-1, item, arr);
    }
    if(item>arr[mid]){
        return binarySearch(mid+1, ei, item, arr);
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int item;
    cin >> item;
    sort(arr, arr+n);
    cout << binarySearch(0,n-1, item, arr) << endl;
}