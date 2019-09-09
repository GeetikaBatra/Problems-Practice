#include<bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j){
    if(i==j){
     return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int part(int *arr, int st, int end){
    
    int count_small=0;
    for(int i = st+1; i<=end; i++){
        if(arr[i]<=arr[st]){
            count_small++;
        }
    }
    
    swap(arr, st, st+count_small);
    
    int i = st;
    int j = end;

    while(i<st+count_small && j>st+count_small){
        if(arr[i]<=arr[st+count_small]){
            i++;
        }
        else if(arr[j]>arr[st+count_small]){
            j--;
        }
        else{
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    return st+count_small;
}
void quick_sort(int *arr, int st, int end){
    if(st>=end){
        return;
    }
    int pivot = part(arr, st, end);
    quick_sort(arr, st, pivot-1);
    quick_sort(arr, pivot+1, end);
}
int main(){
    int n =6;
    int arr[6] = {6, 4, 4 , 3 , 2, 1};
    quick_sort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}

