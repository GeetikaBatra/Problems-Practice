#include<bits/stdc++.h>

using namespace std;

void printStaircase(int sum, string s, int n){
    if(sum==n){
        cout << s << endl;
        return;
    }
    if((n-sum)>=1){
        printStaircase(sum+1, s+"1", n);
    }
    if((n-sum)>=2){
        printStaircase(sum+2, s+"2", n);
    }
  return;
}

int main(){

    int n;
    cin >> n;
    printStaircase(0, "", n);
}
