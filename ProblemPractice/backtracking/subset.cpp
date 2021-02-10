#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void subset(int *arr, int n, vector<vector<int>> &res, vector<int> r){
    if(n==0){
        return;
    }
    r.push_back(arr[0]);
    res.push_back(r);
    subset(arr+1, n-1, res, r);
    r.pop_back();
    subset(arr+1, n-1, res, r);
}

int main(){
    vector<vector<int>> res;
    vector<int> r;
    int arr[3] = {1,2,3};
    sort(arr, arr+3);
    subset(arr, 3, res, r);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
}