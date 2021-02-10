#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

bool isPossible(int board[9][9], int num, int &row, int &col){
    //check row
    
    for(int i=0; i<9; i++){
        if(board[row][i]==num){
            return false;
        }
    }
    //check col
    for(int i=0; i<9; i++){
        if(board[i][col]==num){
            return false;
        }
    }
    //check box
    int row_st = row - (row%3);
    int row_end = row_st+2;

    int col_st = col - (col%3);
    int col_end = col_st + 2;
    for(int i=row_st; i<=row_end; i++){
        for(int j=col_st; j<=col_end; j++){
           if(board[i][j]==num){
            return false;
        }
        }
    }
    return true;
}

bool findEmpty(int board[9][9], int &row, int &col){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]==0){
                row=i; 
                col=j;
                return true;
            }
        }
    }
    return false;
}
  
void sudokuHelper(int board[9][9]){
    int row, col;
    
    if(!findEmpty(board, row, col)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
        return;
    }
    for(int i=1; i<=9; i++){
        if(isPossible(board, i, row, col)){
            board[row][col] = i;
            sudokuHelper(board);
            board[row][col] = 0;
        }
    }
    return;
}

// void sudokuSolver(int board[9][9]){
//     sudokuHelper(board);
// }

int main(){
    

     int board[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    sudokuHelper(board);

}
