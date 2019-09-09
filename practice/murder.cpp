#include<bits/stdc++.h>

using namespace std;

int merge(int *arr, int st, int end, int mid){

        int last_sum =0;
        int sum=0;
        int i=st, j=mid;
        int k=0;
        int temp[end-st+1];

        while(j<=end && i<mid){

            if(arr[i]<arr[j]){
		last_sum =last_sum + arr[i];
		temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                sum = sum + last_sum;
            }
        }
        while(i<mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
	    sum = sum + last_sum;
        }

        while(k--){
            arr[st+k] = temp[k];
        }
        return sum;
}   


int merge_sort(int *arr, int st, int end){

    if(st>=end){
        return 0;
    }
    int mid = (end+st)/2;

    int left_count = merge_sort(arr, st, mid);
    int right_count = merge_sort(arr, mid+1, end);
    int merge_count = merge(arr, st, end, mid+1);
    return left_count + right_count + merge_count;
}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << merge_sort(arr, 0, n-1)<< endl;

}
