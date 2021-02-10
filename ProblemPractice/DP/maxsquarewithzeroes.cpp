#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void maxsquarewithzeroes(int **matrix, int**op, int n){
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]){
                op[i][j] = min(op[i-1][j-1], min( op[i][j-1], op[i-1][j]));
                continue;
            }
            op[i][j] = min(op[i-1][j-1], min( op[i][j-1], op[i-1][j])) + 1;
        }   
    }
}

int main(){
    int n=3;
    int **matrix = new int*[n];
    for(int i=0; i<n; i++){
        matrix[i] = new int[n];
    }
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 0;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix[1][1] = 1;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;

    int **op = new int*[n];
    for(int i=0; i<n; i++){
        op[i] = new int[n];
    }
    for(int i=0; i<n; i++){
        if(matrix[i][0]){
            op[i][0]=0;
        }
        else{
            op[i][0]=1;
        }
    }
    for(int i=0; i<n; i++){
        if(matrix[0][i]){
            op[0][i]=0;
        }
        else{
            op[0][i]=1;
        }
    }
    maxsquarewithzeroes(matrix, op,n );
    // for(int i=0; i<n; i++){
    //    for(int j=0; j<n; j++){
    //        cout <<op[i][j] ;
    //    }
    //    cout<<endl;
    // }
    cout << op[n-1][n-1]<<endl;
}