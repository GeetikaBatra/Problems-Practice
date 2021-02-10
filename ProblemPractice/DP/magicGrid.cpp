// #include "/Users/gbatra/ProblemPractice/stdc++.h"
// using namespace std;

// int find_max(int c_i, int c_j, int **matrix, int &row, int &col){
//     int s1 = INT_MIN;
//     int s2 = INT_MIN;
//     int ret = INT_MIN;

//     cout <<"row"<<"col"<<row<<"   "<< col<<endl;
    
//     if(c_i-1>0){
//         s1 = matrix[c_i-1][c_j];
//     }
//     if(c_j-1>0){
//         s2 = matrix[c_i][c_j-1];
//     }
//     if(s1>s2){
//         if(matrix[c_i-1][c_j]>0){
//             ret = matrix[c_i-1][c_j];
//         }
//         else{
//             ret = 1-matrix[c_i-1][c_j];
//         }
//         row = c_i-1;
//         col = c_j;
//         return ret;
//     }
//     if(matrix[c_i][c_j-1]>0){
//             ret = matrix[c_i][c_j-1];
//         }
//         else{
//             ret = 1-matrix[c_i][c_j-1];
//         }
//         row = c_i;
//         col = c_j-1;
//         return ret;
// }

// void magicGrid(int **matrix, int **op, int si, int sj, int ei, int ej){

//     int i = ei;
//     int j = ej;
    
//     while(true){
//         int row = i;
//         int col = j;
//         int n = find_max(i, j, matrix, row, col);
//         cout <<"row" << "col"<<row<<"   "<< col<<endl;
//         op[row][col] = op[i][j] + n;
//         i = row;
//         j = col;
//         if(i==si && j==sj){
//             break;
//         }
//     }
// }

// int main(){
//     int **matrix = new int*[2];
//     for(int i=0; i<2; i++){
//         matrix[i] = new int[3];
//     }
//     matrix[0][0] =  0;
//     matrix[0][1] =  1;
//     matrix[0][2] = -3;
//     matrix[1][0] =  1;
//     matrix[1][1] = -2;
//     matrix[1][2] =  0;
//     int **op = new int*[2];
    
//     for(int i=0; i<2; i++){
//         op[i] = new int[3];
//         for(int j=0; j<3; j++){
//             op[i][j] = INT_MIN;
//         }
//     }
//     op[1][2] = 1;
//     magicGrid(matrix, op, 0,0, 2,2);
    
//     for(int i=0; i<2; i++){
//         for(int j=0; j<3; j++){
//             cout << op[i][j];
//         }
//     }
// }

#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int solve(vector<vector<int>> &A){
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> hp(m+1, vector<int>(n+1, INT_MAX));
    hp[m][n-1] = 1;
    hp[m-1][n] = 1;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int need = min(hp[i+1][j], hp[i][j+1]) - A[i][j];
            // cout << need<< "  ";
            hp[i][j] = need<=0 ? 1: need;
            // cout << hp[i][j] << endl;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout <<hp[i][j]<<"  ";
        }
        cout <<endl;
    }
    return hp[0][0];
}

int main(){
    int t, m, n, i, j;
    cin >>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> A(n, vector<int>(m));
        for(i=0; i<n; i++)for(j=0; j<m; j++)cin>>A[i][j];
        cout <<solve(A)<<endl;
        
    }
}