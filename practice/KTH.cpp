#include<bits/stdc++.h>
using namespace std;

#define n 8
int board[n][n];

void KTH(int count, int row, int col){
    if(count==63){
       board[row][col]=count;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " " ;
            }
            cout << endl;
        }
	exit(0);
        return;
    }
    cout << count << endl;
    board[row][col]=count;

    if(row+2<n && col+1<n && board[row+2][col+1]==-1){
        KTH(count+1, row+2, col+1);
    }
    if(row+2<n && col-1>=0 && board[row+2][col-1]==-1){
        KTH(count+1, row+2, col-1);
    }
    if(row-2>=0 && col+1<n && board[row-2][col+1]==-1){
        KTH(count+1, row-2, col+1);
    }
    if(row-2>=0 && col-1>=0 && board[row-2][col-1]==-1){
        KTH(count+1, row-2, col-1);
    }
    if(row-1>=0 && col-2>=0 && board[row-1][col-2]==-1){
        KTH(count+1, row-1, col-2);
    }
    if(row+1<n && col-2>=0 && board[row+1][col-2]==-1){
        KTH(count+1, row+1, col-2);
    }
    if(row-1>=0 && col+2<n && board[row-1][col+2]==-1){
        KTH(count+1, row-1, col+2);
    }
    if(row+1<n && col+2<n && board[row+1][col+2]==-1){
        KTH(count+1, row+1, col+2);
    }
    board[row][col]=-1;
    return;
}

int main(){
    memset(board,-1, 8*8*sizeof(int));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
        {
            KTH(0, i, j);
        }
    }
    
}
