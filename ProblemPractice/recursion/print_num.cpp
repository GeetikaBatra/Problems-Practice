#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void print_num(int n){
    if(n==1){
        cout<<1<< " ";
        return;
    }
    print_num(n-1);
    cout << n << " ";
    return;
}

int main(){
    print_num(6);
    cout <<endl;

}