#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int minCost(int **matrix, int n, int si, int sj, int ei, int ej){
        if(si==ei && sj==ej){
            return matrix[si][sj];
        }
        // if(si<ei || sj<ej){
        //     return INT_MAX;
        // 
        int s1=INT_MAX, s2=INT_MAX, s3=INT_MAX;
        if(ei-1>=0){
           s1 =  minCost(matrix, n, si, sj, ei-1, ej);
        }
        if(ej-1>=0){
            s2 = minCost(matrix, n, si,sj, ei, ej-1);
        }
        if(ei-1>=0 && ej-1>=0){
            s3 = minCost(matrix, n, si, sj, ei-1, ej-1);
        }
        // cout <<s1<<s2<<s3<<endl;
        return matrix[ei][ej] + min(min(s1,s3), s2);
}

int minCostRecDP(int **matrix, int n, int si, int sj, int ei, int ej, int **op){
    if(si==ei && sj==ej){
        op[si][sj] = matrix[si][sj];
        return op[si][sj];
    }
    if(op[ei][ej]){
        return op[ei][ej];
    }
    int s1 =INT_MAX, s2= INT_MAX, s3=INT_MAX;
    if(ei-1>=0){
           s1 =  minCost(matrix, n, si, sj, ei-1, ej);
        }
    if(ej-1>=0){
        s2 = minCost(matrix, n, si,sj, ei, ej-1);
    }
    if(ei-1>=0 && ej-1>=0){
        s3 = minCost(matrix, n, si, sj, ei-1, ej-1);
    }
    op[ei][ej]=matrix[ei][ej]+ min(s1,min(s2,s3));
   return op[ei][ej];
}

void minCostIterDP(int **matrix, int n, int **op){
    op[0][0] = matrix[0][0];
    for(int i=1; i<3; i++){
        op[0][i] = op[0][i-1]+ matrix[0][i];
    }
    for(int i=1; i<3; i++){
        op[i][0] = op[i-1][0] + matrix[i][0];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            int s1 = INT_MAX;
            int s2 = INT_MAX;
            int s3 = INT_MAX;
            if(i-1>=0){
                s1 = op[i-1][j];
            }
            if(j-1>=0){
                s2= op[i][j-1];
            }
            if(i-1>=0 && j-1>=0){
                s3 = op[i-1][j-1];
            }
            op[i][j] = matrix[i][j] + min(s1,min(s2,s3));
        }
    }
}

int main(){
    int **matrix = new int*[3];
    for(int i=0; i<3; i++){
        matrix[i] = new int[3];
    } 
    matrix[0][0] = 4;
    matrix[0][1] = 3;
    matrix[0][2] = 2;
    matrix[1][0] = 1;
    matrix[1][1] = 8;
    matrix[1][2] = 3;
    matrix[2][0]=  1;
    matrix[2][1] = 1;
    matrix[2][2] = 8;
    int **op  = new int*[3];
    for(int i=0; i<3;i++){
        op[i] = new int[3];
        for(int j=0; j<3; j++){
            op[i][j]=0;
        }
    }
    // cout <<minCost(matrix,3,0,0,2,2)<<endl;
    minCostIterDP(matrix, 3, op);
    cout<<op[2][2]<<endl;
}

// PRACTICE ANSWER
// #include "/Users/gbatra/ProblemPractice/stdc++.h"
// using namespace std;

// //Recursive memoization way
// void minCostRec(int **matrix, int si, int sj, int ei, int ej,  int **op){
//         if(si==ei && sj==ej){
//             op[si][sj]=matrix[si][sj];
//             return;
//         }
//         //check left
//         int s1=INT_MAX, s2=INT_MAX, s3=INT_MAX;
//         if(ej-1>=0){
//             if(!op[ei][ej-1]){
//                 minCostRec(matrix, si, sj, ei, ej-1, op);
//             }
//            s1 = op[ei][ej-1];
//         }
//         //check up
//         if(ei-1>=0){
//             if(!op[ei-1][ej]){
//                 minCostRec(matrix, si, sj, ei-1, ej, op);
//             }
//            s2 = op[ei-1][ej];
//         }
//         //check diagonally
//         if(ei-1>=0 && ej-1>=0){
//             if(!op[ei-1][ej-1]){
//                 minCostRec(matrix, si, sj, ei-1, ej-1, op);
//             }
//             s3 = op[ei-1][ej-1];
//         }
//         op[ei][ej] = min(s1, min(s2,s3)) + matrix[ei][ej];
// }

// int minCostIter(int **matrix, int n, int si, int sj, int ei, int ej,  int **op){
//         op[0][0] = matrix[0][0];
//         for(int i=1; i<n; i++){
//            op[i][0] =op[i-1][0]+ matrix[i][0];
//         }
//         for(int i=1; i<n; i++){
//            op[0][i] =op[0][i-1]+ matrix[0][i];
//         }
//         for(int i=1; i<n ;i++){
//             for(int j=1; j<n; j++){
//                 op[i][j]= matrix[i][j] + min(op[i][j-1], min(op[i-1][j-1], op[i-1][j]));
//             }
//         }
        
//     return op[ei][ej];
// }

// int main(){
//     int **matrix = new int*[3];
//     for(int i=0; i<3; i++){
//         matrix[i] = new int[3];
//     } 
//     matrix[0][0] = 4;
//     matrix[0][1] = 3;
//     matrix[0][2] = 2;
//     matrix[1][0] = 1;
//     matrix[1][1] = 8;
//     matrix[1][2] = 3;
//     matrix[2][0]=  1;
//     matrix[2][1] = 1;
//     matrix[2][2] = 8;
//     int **op  = new int*[3];
//     for(int i=0; i<3;i++){
//         op[i] = new int[3];
//         for(int j=0; j<3; j++){
//             op[i][j]=0;
//         }
//     }
//     // minCostRec(matrix,0,0,2,2, op);
//     // minCostIterDP(matrix, 3, op);
//     // cout<<op[2][2]<<endl;
//     cout<<minCostIter(matrix,3, 0,0,2,2,op)<<endl;
// }