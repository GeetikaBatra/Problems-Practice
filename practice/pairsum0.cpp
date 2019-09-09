#include<bits/stdc++.h>
using namespace std;

void pairSum0(int *arr, int n){
    unordered_map<int, int> count_map;
    for(int i=0; i<n; i++){
        int  temp = arr[i];
        if(count_map.find(-temp)!=count_map.end()){
            for(int j=0; j<count_map[-temp]; j++){
                cout << min(temp, -temp) << " "  << max(temp, -temp) << endl;
            }
        }
        if(count_map.find(temp)!=count_map.end()){
            count_map[temp]++;
        }
        else{
            count_map[temp]=1;
        } 
    }
}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    pairSum0(arr,n);
  // 1st solution with 2 iterations
    // unordered_map<int, int> count_map;
    // for(int i=0; i<n; i++){
    //     if(count_map.find(arr[i])==count_map.end()){
    //         count_map[arr[i]]=1;
    //     }

    //     else{
    //         count_map[arr[i]]++;
    //     }
    // }


    // for(int i=0; i<n; i++){
    //     int temp = arr[i];
    //     if(temp==0){
    //         continue;
    //     }
    //     if(count_map.find(-temp)!=count_map.end()){
    //         int v1 = count_map[temp];
    //         int v2 = count_map[-temp];
    //         for(int j=0; j<v1*v2; j++){
    //             cout << min(arr[i], -arr[i]) << max(arr[i], -arr[i]);
    //         }
    //         arr[temp] = 0;

    //     }
    // }
}
