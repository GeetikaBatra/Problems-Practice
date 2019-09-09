#include <bits/stdc++.h>

using namespace std;

int getD(int start, int end){
    return (start+end)/2;
}

// unordered_map<int, bool> resetMap(unordered_map<int,bool> check_map, int n, int *arr){
//     check_map[arr[0]] = true;

//     for(int i=1; i<n; i++){
//         check_map[arr[i]] = false;

//     }
//     return check_map;
//} 

void maxD(int n, int *arr, int cows){

    if(n==0){
        cout << 0 << endl;
        return;
    }
    
    int start = arr[0];
    int end = arr[n-1];
    int max_d = 0;
    // unordered_map<int, bool> check_map;
    // check_map[arr[0]] = true;
    // for(int i=1; i<n; i++){
    //     check_map[arr[i]]==false;
    // }

    while(start<end){// do start < end
        int temp = cows-1;
        int d=getD(start, end);

        // resetMap(check_map, n ,arr);
        int last_pos = 0;
        for(int i=1; i<n; i++){
            if((arr[i]-arr[last_pos])>=d){
                last_pos = i;
                temp--;
                // check_[arr[i]] = true;
            }
            if(temp==0){
                break;
            }
        }
        if(temp!=0){
            end = d-1;
        }
        else{
            if(max_d<d){
                max_d = d;
            }
	    start=d+1;
    }
    }
    cout << max_d << endl;

}
int main(){
    int n;
    int cows;
    int arr[n];

    cin >> n >> cows;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    maxD(n, arr, cows);
}
