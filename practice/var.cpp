#include<bits/stdc++.h>

using namespace std;
int check_k(int *arr, int st, int k, int n,int elem){
    int start = st;
    int end = n-1;
    int result =-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(abs(arr[mid]-elem)>=k){
            end = mid-1;
            result = mid;
        }
        else{
            start = mid+1;
        }
    }
    return result;
}
int main(){
    int n,k;

    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int pair = 0;

    for(int i=0; i<n-1; i++){

        int elem = arr[i];
        int nearest_index = check_k(arr, i+1, k, n, elem);

        if(nearest_index!=-1){
            pair+=(n-nearest_index);
        }
    }
    cout << pair << endl;
}
