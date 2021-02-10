#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
void test(int *out, int n){
    for(int i=0; i<n; i++){
        out[i] =1;
    }

}

int main(){
    int op[6];
    for(int i=0; i<6; i++){
        op[i] =1;
    }
    // test(op, 6);
    int out[6];
    test(out, 6);
    for(int i=0; i<6; i++){
        cout<<out[i]<<endl;
    }

}