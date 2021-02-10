#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void cs2(int *arr, int T, int n, vector<vector<int>> &result, vector<int> r){
    if(T==0){
        result.push_back(r);
        return;
    }
    if(T<0 || n==0){
        return;
    }
    r.push_back(arr[0]);
    cout <<arr[0]<<endl;
    cs2(arr+1, T-arr[0], n-1, result, r);
    r.pop_back();
    cs2(arr+1, T, n-1, result, r);

}
int main(){
    int arr[7] = {10,1,2,7,6,1,5};
    // int *arr = new int[7];
    // arr[0]=10;
    // arr[1]=1;
    // arr[2]=2;
    // arr[3]=7;
    // arr[4]=6;
    // arr[5]=1;
    // arr[6]=5;

    int T = 8;
    vector<vector<int>> result;
    vector<int> r;
    cs2(arr, T, 7, result, r);
    for(int i=0; i<result.size(); i++){
        cout << "[";
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j]<<",";
        }
        cout << "]"<<endl;
    }
}