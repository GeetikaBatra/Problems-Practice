#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
// int findMaxSquareWithAllZeroes(int **arr, int row, int col)  {
//     int **storage;
//     storage = new int*[row+1];
//     for(int i=0; i<=row; i++){
//         storage[i] = new int[col+1];
//         for(int j=0; j<=col+1; j++){
//             storage[i][j]=0;
//         }
//     }
//     for(int i=row-1; i>=0; i--){

//     }
// }

int getMaxSub(int **arr, int n, int m){
    int **dp = new int*[n];
    for(int i=0; i<n;i++){
        dp[i] = new int[m];
    }
    int max_sub = 0;
    for(int i=0; i<n; i++){
        dp[i][0] = !arr[i][0];
        if(max_sub<dp[i][0]){
                    max_sub=dp[i][0];
                }
    }
    for(int i=0; i<m; i++){
        dp[0][i] = !arr[0][i];
        if(max_sub<dp[0][i]){
                    max_sub =dp[0][i];
                }
    }
    
    for(int i=1; i<n;i++){
        for(int j=1; j<m; j++){
            if(arr[i][j]==0){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1;
                
                if(max_sub<dp[i][j]){
                    max_sub=dp[i][j];
                }
            }
            if(arr[i][j]==1){
                dp[i][j]=0;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout <<dp[i][j];
        }
        cout <<endl;
    }
    return max_sub;
}

int main(){
    int n,m;
    cin >>n>>m;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }
    for(int i=0;i <n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout << getMaxSub(arr, n,m)<< endl;
}