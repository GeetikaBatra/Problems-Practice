#include<bits/stdc++.h>
using namespace std;


bool isPossible(int maze[][3], int **board, int n, int row, int col){
    if(row<0 || row >n-1 || col <0 || col >n-1){
        return false;
    }
    if(board[row][col] == 0 && maze[row][col] ==1){
        return true;
    }
    return false;
}

void ratMAzeHelper(int maze[][3], int** board, int n, int row, int col){

    
    if(row==n-1 && col==n-1){
	    board[row][col] =1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j];
            }
        }
        cout << endl;
        return;
    }

    if(isPossible(maze, board, n, row, col)){
        board[row][col]=1;
        
        ratMAzeHelper(maze, board, n, row, col-1);
        ratMAzeHelper(maze, board, n, row-1, col);
        ratMAzeHelper(maze, board, n, row, col+1);
        ratMAzeHelper(maze, board, n, row+1, col);

        board[row][col] =0;
    }

    return;
}

void ratMaze(int maze[][3], int n){
    int **board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
    }
    ratMAzeHelper(maze, board,n, 0, 0);

}

int main(){
    int maze[3][3];
    maze[0][0] =1;
    maze[0][1] = 0;
    maze[0][2] = 1;
    maze[1][0] = 1;
    maze[1][1] = 0;
    maze[1][2] = 1;
    maze[2][0] = 1;
    maze[2][1] = 1;
    maze[2][2] = 1;

    ratMaze(maze, 3);


}
