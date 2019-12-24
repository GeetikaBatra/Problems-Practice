#include<bits/stdc++.h>
using namespace std;

void ceilAndRec(int *arr, int n){
   
    for(int i=0;i<n;i++){
        int count=0;
        int num = arr[i];
        int j=0;
        int x = 1<<j;
        while(num>=x){
            
            if(j==12){
                break;
            }
            j++;      
    }
    j--;
    // cout<< j << " " <<(1<<j)<<endl;
    while(num!=0){
        // cout << (1<<j) << endl;
        count+=(num/(1<<j));
        num = num%(1<<j);
        j--;
    }
    cout << count << endl;
    }
}
int main(){
    int T;
    cin >> T;
    int arr[T];
    int i=0;

    while(i<T){
        cin>>arr[i];
        i++;
    }
    ceilAndRec(arr, T);
}