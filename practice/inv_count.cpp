#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll merge(int *A, ll st, ll mid, ll end){
    int temp[end-st+1];
    ll inv_count = 0;
    ll k = 0;
    ll i=st, j=mid;
    while(i<mid && j<=end){
        if(A[i]<=A[j]){
            temp[k++] = A[i++];
        }
        else{
            inv_count+=mid-i;
            temp[k++] = A[j++];
        }
    }
    while(i<mid){
        temp[k++] = A[i++];
    }
    while(j<=end)
    {
        temp[k++] = A[j++];

    }
    for(ll i=0; i<k; i++)
    {
        A[st+i] = temp[i];
    }
    return inv_count;
}
ll merge_sort(int *A, ll n, ll st, ll end){
    if(st>=end){
        return 0;
    }
    ll mid = (st+end)/2;
    ll left_count = merge_sort(A, n, st, mid);
    ll right_count = merge_sort(A,n, mid+1, end);

    ll merge_count = merge(A, st, mid+1, end);

    return left_count + right_count + merge_count;
}


int main(){
    int A[] = {3,2,1};
    int st = 0;
    int end = 2;

    cout << merge_sort(A, 3, 0, 2) << endl;
}

