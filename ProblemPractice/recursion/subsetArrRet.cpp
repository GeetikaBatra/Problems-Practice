// #include "/Users/gbatra/ProblemPractice/stdc++.h"
// using namespace std;

// int subset(int input[], int n, int startIndex, int output[][20]){
//     if(startIndex==n){
//         output[0][0] =0;
//         return 1;
//     }
//     int smallSize = subset(input, n, startIndex+1, output);
//     for(int i=0; i<smallSize; i++){
//         output[i+smallSize][0] = output[i][0]+1;
//         output[i+smallSize][1] = input[startIndex];
//         for(int j=1; j<=output[i][0]; i++){
//             output[i+smallSize][j+1]  = output[i][j];
//         }
//     }
//     return 2* smallSize;
// }

// int subset(int input[], int n, int output[][20]){
//     return subset(input, n, 0, output);
// }


#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main(){
    int *arr = new int[3];
    int **output = new int*[1<<3];
    for(int i=0; i<3; i++){
        
    }
}