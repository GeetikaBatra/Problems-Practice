#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int staircase(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 1;
    }
    int s1 = staircase(n-1);
    int s2= staircase(n-2);
    int s3= staircase(n-3);
    int res = 0;
    if(s1 !=-1 ){
        res+=s1;
    }
    if(s2!=-1){
        res+=s2;
    }
    if(s3!=-1){
        res+=s3;
    }
    return res;
}

int main(){
    int n = 5;
    cout<< staircase(n)<< endl;
}