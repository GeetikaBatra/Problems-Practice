#include<bits/stdc++.h>
using namespace std;
#define N 4

int solMatrix[11][11];

void ratMaze(int maze[N][N], int row, int col){
    if(row==N-1 && col==N-1){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << solMatrix[i][j]<< " ";
            }
            cout << endl;
        }
        return;
    }
    solMatrix[row][col]=1;
    if(col+1<N && maze[row][col+1]==1){
        
        ratMaze(maze, row, col+1);
        
    }
    if(col+1<N && maze[row+1][col]==1){
        ratMaze(maze, row+1, col);
        
    }
    solMatrix[row][col]=0;
    return;
}
int main(){
    int maze[N][N] = { { 1, 0, 0, 0 },
                      { 1, 1, 0, 1 },
                      { 0, 1, 0, 0 },
                      { 1, 1, 1, 1 } };
    memset(solMatrix, 0, 11*11*sizeof(int));
    ratMaze(maze,  0, 0);
}
