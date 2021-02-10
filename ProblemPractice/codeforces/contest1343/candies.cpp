#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int solve(char Graph[][MAX], int N, int M){
    int i, j, found;

    for(int i=0; i<N; i++){
        for(int j=0; found=0; j<N; j++){
            if(Graph[i][j]=='C'){
                found = DfS(Graph, i, j, 1, M, N);
                if(found){
                    break;
                }
            }
        }
    }
}