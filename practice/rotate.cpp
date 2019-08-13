#include<bits/stdc++.h>
using namespace std;

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int temp[d];
    
    for(int i=0; i<d; i++){
        temp[i]=arr[i];
    }
    
    for(int i=d; i<size; i++){
        arr[i-d] = arr[i];
    }
    
    for(int i=0; i<d; i++){
        arr[size-d+i] = temp[i];
    }
   
    for(int i=0; i<size; i++){
        cout << arr[i] + " ";
    }
}


int main(){
   int size;
   cin >> size;
   int arr[size];
   for(int i=0; i<size; i++){
     cin >> arr[i];
    

}
 int d;
 cin >> d;

Rotate(arr, d, size);

}
