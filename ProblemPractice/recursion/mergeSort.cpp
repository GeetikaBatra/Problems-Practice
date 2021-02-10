#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void merge(int *arr, int si, int mid, int ei){
    int *new_arr= new int[ei-si+1]{0};
    // memset()
    int i=si;
    int j=mid+1;
    int k=0;
    // for(int m=si; m<=ei; m++){
    //     cout<<arr[m];
    // }
    // cout <<" end ar"<<endl;
    while(i<=mid && j<=ei){
            if(arr[i]<arr[j]){
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        else{
            new_arr[k] = arr[j];
            j++;
            k++;
        }
    }
        while(i<=mid){
             new_arr[k]=arr[i];
             i++;
             k++;
        }
        while(j<=ei){
             new_arr[k] = arr[j];
             j++;
             k++;
        }
        for(int m=0; m<k; m++){
        
        
    }
    //  cout<<endl;
    for(int m=0; m<k; m++){
        // cout<<new_arr[m]<<endl;
        
        arr[si+m] = new_arr[m];
    
    }
}

void merge_sort(int *arr,  int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    merge_sort(arr, si, mid);
    merge_sort(arr, mid+1, ei);
    merge(arr, si,mid, ei);
}

int main(){
    int n=6;
    int arr[6] = {7, 6, 5, 3, 4, 1};
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout <<arr[i]<<endl;
    }
}