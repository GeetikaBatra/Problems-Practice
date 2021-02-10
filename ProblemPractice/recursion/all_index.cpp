#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// void find(int *arr,int n, int x, int *op, int* l){
//     if(n==0){
//         return;
//     }
//     if(arr[n-1]==x){
//         op[*l] = n-1;
//         *l = *l+1;
//     }
//     find(arr, n-1, x, op, l);
//     return;
// }

// int main(){
//     int *arr = new int[6]{6,5,4,3,2,5};
//     int *op = new int[6];
//     int l=0;
//     find(arr, 6, 5, op, &l);
//     for(int i=0; i<l; i++){
//         cout <<op[i]<<endl;
//     }
// }
// #include<bits/stdc++.h>
// using namespace std ;


 void first(int* arr,int n,int x,int* output, int *l){
    if(n==0){
        return ;
    }
    if(arr[n-1]==x){
        output[*l] = n-1  ;
        *l = *l++ ;
    }

        first(arr,n-1,x,output,&l) ;

}


 


int main(){
    int numb[6] = {6,9,6,9,65,1} ;
    int output[6] ;
    
    int l =0 ;
    // int *ptr = &l;
    // cout <<*[ptr]
    first(numb,6,9,output,&l);
    for(int i =0 ;i<l;i++){
        cout<<output[i]<<endl ;
    }

}

