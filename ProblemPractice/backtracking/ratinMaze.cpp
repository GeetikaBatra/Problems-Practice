#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int maze[20][20];

void printSolMat(int **solMat, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << solMat[i][j]<< " ";
            }
            cout << endl;
        }
}
void ratInMazeHelper(int **solMat, int n, int row, int col){
        if(row==n-1 && col==n-1){
            solMat[row][col] = 1;
            printSolMat(solMat, n);
            solMat[row][col] =0;
            return;
        }
    if(row<0 || row>=n || col <0|| col>=n || maze[row][col]==0 || solMat[row][col]==1){
        return;
    }

    
    solMat[row][col]=1;
    ratInMazeHelper(solMat, n, row-1, col);
    ratInMazeHelper(solMat, n, row+1, col);
    ratInMazeHelper(solMat, n, row, col+1);
    ratInMazeHelper(solMat, n, row, col-1);
    solMat[row][col] =0; 
    return;

}
void ratInMaze( int n){
    int **solMat = new int*[n];
    for(int i=0; i<n; i++){
        solMat[i] = new int[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            solMat[i][j] =0;
        }
    }
    
    ratInMazeHelper(solMat, n, 0, 0);
}

int main(){

    int n=3;
    maze[0][0] =1;
    maze[0][1] =0;
    maze[0][2] =1;
    maze[1][0] =1;
    maze[1][1] =0;
    maze[1][2] =1;
    maze[2][0] =1;
    maze[2][1] = 1;
    maze[2][2] =1;
    ratInMaze(n);
}