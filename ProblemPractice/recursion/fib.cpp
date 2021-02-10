#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int main(){
    int n=10;
    cout<<fib(n-1)<<endl;
//    int n=10;
   
//    int x = 0;
//    int y =1;
//    if(n==0){
//        cout << x<< endl;

//    }
//    if(n==1){
//        cout<<y<<endl;
//    }
//    for(int i=2; i<n; i++){
//        int temp;
//        temp =x+y;
//        x=y;
//        y=temp;
//    }
//    cout <<y<<endl;

}