#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void coinChange(int n, int numD, int *den){
    int **op = new int*[numD+1];
    for(int i=0; i<=numD;i++){
        op[i] = new int[n+1];
    }
    for(int j=1; j<=n; j++){
            op[0][j] = 0;
    }
    for(int i=0; i<=numD; i++){
        op[i][0] = 1;
    }
    for(int i=1; i<=numD; i++){
        for(int j=1; j<=n; j++){
            
            op[i][j] = op[i-1][j];
            if(j-den[numD-i]>=0){
               op[i][j] += op[i][j-den[numD-i]];
            }
        }
    }
    for(int i=0; i<=numD; i++){
        for(int j=0; j<=n; j++){
            cout <<op[i][j];
        }
        cout <<endl;
    }
    cout<<op[numD][n]<<endl;
}

int main(){
    int n = 4;
    int *numD = new int[3]{1, 2 ,3};
    coinChange(n, 3, numD);
}

