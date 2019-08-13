#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int input_arr[n];
    int output_arr[n];
    
    for(int i=0; i<n; i++){
        cin >> input_arr[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> output_arr[i];
    }
    int max_chairs = 0;//Int mini
    
    sort(input_arr, input_arr + n);
    sort(output_arr, output_arr+n);
    int i=0;
    int j=0;
    int count = 0;
    while(i<n && j<n){
        if(input_arr[i] < output_arr[j]){
            count++;
            i++;
        }
        else if(input_arr[i] > output_arr[j]){
            count--;
            j++;
        }
       if(count>max_chairs){
           max_chairs = count;
       }
    }
	// Write your code here
    cout << max_chairs << endl;
}
