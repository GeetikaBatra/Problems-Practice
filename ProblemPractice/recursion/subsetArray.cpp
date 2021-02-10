#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int get_subsets(int *arr, int **matrix, int n){
    if(n==0){
        matrix[0][0] = 0;
        return 1;
    }
    int pre_subsets = get_subsets(arr+1, matrix,  n-1);

    for(int i=0;i<pre_subsets; i++){
        matrix[i+pre_subsets][0] = matrix[i][0] +1;
        matrix[i+pre_subsets][1] = arr[0];
        for(int j=0; j<matrix[i][0]; j++){
            matrix[i+pre_subsets][j+2] = matrix[i][j+1];
        }
    }

    return 2*pre_subsets;
}
void print_subsets(int **matrix, int n){
    for(int i=0; i<n;i++){
        int j_max = matrix[i][0];
        cout << j_max<< " ";
        for(int j=1; j<=j_max; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    int n =3;
    int *arr=new int[]{1,2,3};
    int **matrix = new int*[(1<<(n+1))];
    for(int i=0;i<(1<<(n+1));i++){
        matrix[i] = new int[n+1];
    }
    int subsets = get_subsets(arr,matrix, n);
    print_subsets(matrix, subsets);

}