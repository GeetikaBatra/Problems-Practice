
#include<bits/stdc++.h>
using namespace std;

int maxCandy(int *arr, int k, int n){
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    sort(arr, arr+n);
    int start= arr[0];
    int end = arr[n-1];
    int maxCandy = 0;
    while(start<=end){
        int d_candy = (start+end)/2;
        int total_candy =0;
        for(int i=0;i<n; i++){
            total_candy = total_candy+(arr[i]/d_candy);
	}
        if(total_candy>=k){
	
                start = d_candy+1;
                maxCandy = d_candy; 
            }
            else{
                end = d_candy;
            }    
    }
    return maxCandy;
}
int main(){

    int t;
   cin >> t;

    vector<int> result;
     int i=t;
     while(i--){

        int n, k;
        cin >> n >> k;

        int arr[n];

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

         result.push_back(maxCandy(arr, k, n));
     }
     i=0;
    while(i<t){
        cout << result[i]<<endl;
       i++;
    }
return 0;
}

