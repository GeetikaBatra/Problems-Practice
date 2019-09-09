#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int st,int mid, int end){
    int temp[end-st+1];
    int i = st;
    int j = mid;
    int k=0;

    while(i<mid && j<=end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(int i=0; i<k; i++){
        arr[st+i] = temp[i];
    }
}
void merge_sort(int *arr, int st, int end){
    if(st>=end){
        return;
    }
    int mid = (st+end)/2;

    merge_sort(arr, st, mid);
    merge_sort(arr, mid+1, end );
    merge(arr, st, mid+1, end);

    return;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<< arr[i] <<endl;
    }
}
