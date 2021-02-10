#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void combinations(int *arr, int n, int x, vector<vector<int>> &result, vector<int> r){
    if(x<0){
        return;
    }
    if(x==0){
        result.push_back(r);
        return;
    }
    if(n<=0){
        return;
    }
    r.push_back(arr[0]);
    combinations(arr, n, x-arr[0], result, r);
    r.pop_back();
    combinations(arr+1,n-1, x, result, r);
}

int main(){
    int *arr = new int[4];
    arr[0]=2;
    arr[1]=4;
    arr[2]=6;
    arr[3]=8;

    int x=8;
    vector<vector<int>> result;
    vector<int> r;
    combinations(arr,4, x, result, r);
    for(int i=0; i<result.size(); i++){
        cout << "[";
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j]<<",";
        }
        cout << "]"<<endl;
    }
}