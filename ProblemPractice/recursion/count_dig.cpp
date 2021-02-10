#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int counDigi(int n){
    if(n==0){
        return 0;
    }
    n=n/10;
    return 1 + counDigi(n);
}
int main(){
    int n = 634643;
    // if(n==0){
    //     cout <<0<< endl;
    //     return 0;
    // }
    // int count =0;
    // while(n!=0){
    //     count++;
    //     n=n/10;
    // }
    // cout << count<< endl;
    cout<<counDigi(n)<<endl;

}