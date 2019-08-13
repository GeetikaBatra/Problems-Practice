#include<bits/stdc++.h>
using namespace std;

void tripleSum(){
int arr[157]={19,21,2,19,23,17,8,18,29,9,21,20,1,11,27,22,7,7,29,27,12,1,3,21,28,17,8,15,30,17,19,5,27,6,2,18,3,26,21,15,6,17,29,26,16,23,16,29,6,30,24,24,1,13,7,22,17,29,23,16,5,19,25,29,27,23,24,26,22,1,23,10,29,7,12,4,1,24,8,23,4,13,21,13,27,12,13,23,4,4,14,29,29,12,1,24,8,18,6 ,4 ,7 ,18 ,1 ,12 ,1 ,12 ,24 ,30 ,28 ,27 ,21 ,16 ,18 ,14 ,7 ,27 ,9 ,19 ,21 ,9 ,2 ,22 ,10 ,14 ,20 ,4 ,12 ,19 ,9 ,17 ,12 ,8 ,11 ,10 ,10 ,14 ,17 ,20 ,14 ,2 ,20 ,26 ,25 ,19 ,22 ,13 ,18 ,7 ,10 ,11 ,25 ,7 ,8 ,1 ,28 ,14 ,10};
int s = 157;

int x=54;
sort(arr, arr+s);
for(int i=0; i<s; i++){
 int l = i+1;
int r = s-1;

while(l<r){
   int current_sum = arr[i] + arr[l] + arr[r];
   if(current_sum==x){
       cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
       l++;
       r--;
   }
   if(current_sum<x){
       l++;
   }
   if(current_sum>x){
       r--;
   }
}

}
return;
}


int main(){
  int elem_len;
  cin >> elem_len;
  int arr[elem_len];
  for(int i=0; i<elem_len; i++){
  cin >> arr[i];
 }
 int x;
 cin >> x;
// for(int i=0; i<elem_len; i++){
//     for(int j=i+1; j<elem_len; j++){
//         int elem = x-arr[i] - arr[j];
 //        for( int k=j+1; k<elem_len; k++){
 //            if(arr[k]==elem){
 //                cout << arr[i] << arr[j] << arr[k] << endl;
 //            }
  //       }
  //   }
//}

tripleSum();

return 0;
}

