#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col){

    //check col
    for(int i=row-1; i>=0; i--){
        if(board[i][col]){
            return false;
        }
    }
    

    //check leftdiag
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }

    //check rightdiag
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

void nQueenHelper(int n, int row){
    //print the solution
    if(row==n)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " " ;
            }
            cout << endl;
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(isPossible(n, row, i)){
            board[row][i]=1;
            nQueenHelper(n, row+1);
            board[row][i]=0;
        }
    }
    return;
}
void nqueen(int n){
    memset(board, 0, 11*11*sizeof(int));
    nQueenHelper(n,0);
}

int main(){
    int n;
    cin >>n;
    nqueen(n);
    

}
