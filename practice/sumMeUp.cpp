#include<bits/stdc++.h>
using namespace std;

int sumNum(int n){
    int tempSum=0;
    
    while(n!=0){
        tempSum = tempSum + (n%10);
        n = n/10;
    }
    
    return tempSum;
}
int main() {

    int t;
    cin >> t;
    int arr[t];
    
    for(int i=0; i<t; i++){
        cin >> arr[i];
        
    }
    
    for(int i=0; i<t; i++){
        cout << sumNum(arr[i]) << endl;
    }
	// Write your code here
    
}
