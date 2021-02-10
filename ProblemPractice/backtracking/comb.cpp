#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void comb(int *arr, int k, int n, vector<vector<int>> &res, vector<int> r){
    if(k==0){
        res.push_back(r);
        return;
    }
    if(n==0){
        return;
    }
    r.push_back(arr[0]);
    comb(arr+1, k-1, n-1, res, r);
    r.pop_back();
    comb(arr+1, k, n-1, res, r);
}

int main(){
    vector<vector<int>> res;
    vector<int> r;
    int arr[4] = {1,2,3,4};
    comb(arr, 3, 4, res, r);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
}

