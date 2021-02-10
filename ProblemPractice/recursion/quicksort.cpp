#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// int partitionArray(int *input, int start, int end){
//     int pivot = input[start];
//     int count =0;
//     for(int i=start+1; i<=end; i++){
//         if(input[i]<=pivot){
//             count++;
//         }
//     }
//     int pivotIndex = start+count;
//     int temp = input[start];
//     input[start] = input[pivotIndex];
//     input[pivotIndex] = temp;
//     int i=start, j=end;
//     while(i<=pivotIndex && j>=pivotIndex){
//         while(input[i]<=pivot){
//             i++;
//         }
//         while(input[j]>pivot){
//             j--;
//         }
//         if(i<pivotIndex && j>pivotIndex){
//             int temp = input[i];
//             input[i] = input[j];
//             input[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     return pivotIndex;
// }

// void quicksort(int *input, int start, int end){
//     if(start>=end){
//         return;
//     }
//     int pivotIndex = partitionArray(input, start, end);
//     quicksort(input, start, pivotIndex-1);
//     quicksort(input, pivotIndex+1, end);
// }

void swap(int first, int sec, int *arr){
    int temp = arr[first];
    arr[first] = arr[sec];
    arr[sec] = temp;
}

void q_sort_helper(int *arr, int n, int si){
    if(si>=n){
        return;
    }
    int pivot = arr[si];
    int count_ = 0;
    for(int i=si+1; i<=n; i++){
        if(arr[i]<pivot){
            count_++;
        }
    }
    int pivot_index = si+count_;
    swap(si, pivot_index, arr);
    int left = pivot_index-1;
    int right = pivot_index+1;

    while(left>=0 && right<=n){
        while(arr[left]<pivot){
            left--;
        }
        while(arr[right]>pivot){
            right++;
        }
        if(left>=0 && right<=n){
            swap(left, right, arr);
            left--;
            right++;
        }
        
    }
    q_sort_helper(arr, pivot_index-1, si);
    q_sort_helper(arr, n, pivot_index+1);
}

void q_sort(int *arr, int n){
    q_sort_helper(arr, n-1, 0);
}

int main(){
    int arr[6] = {7, 6, 4,3, 1,2};
    q_sort(arr, 6);
    for(int i=0; i<6; i++){
        cout << arr[i]<<endl;
    }
}
