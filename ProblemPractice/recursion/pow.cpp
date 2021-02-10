#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int pow(int x, int n){
    if(n==0){
        return 1;
    }
    int res = pow(x, n-1) * x;
    return res;
}
int main(){
    int x,n;
    cin>>x>>n;
    cout<<pow(x,n)<<endl;
    return 0;
}