#include<bits/stdc++.h>
using namespace std;

void LIS(int *arr, int n){
    int max_len = 0;
    int start = -1;

    sort(arr, arr+n);
    
    int curr_len =0;

    for(int i=1; i<n; i++){

        if((arr[i]-arr[i-1])==1){
            curr_len=curr_len+1;
	    if(curr_len+1>max_len){
                max_len = curr_len + 1;
                start = arr[i] - (curr_len);
            }

       }
else{
	curr_len = 0;
}
        }
    for(int i=0; i<max_len; i++){
        cout << start + i << endl;
    }

 }

void lisMap(int *arr, int n){
    int max_len = 0;
    int start = -1;

    unordered_map<int,bool> check_map;
    for(int i=0; i<n; i++){
        check_map[arr[i]]= true;
    }

    int len;

    for(int i=0; i<n; i++){
        
        if(!check_map[arr[i]]){

            continue;

        }
        len =1;
        int temp = arr[i];
        check_map[arr[i]] = false;

        while(check_map[++temp]){
            len++;
            check_map[temp]=false;

        }
        temp = arr[i];
        while(check_map[--temp]){

	    	len++;
            check_map[temp]=false;
        
        }

        if(len>max_len){
            max_len = len;
            start = temp +1;
        }
    }

    for(int i=0; i<max_len; i++){
        cout << start + i << endl;
    }




}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    lisMap(arr,n);
}
