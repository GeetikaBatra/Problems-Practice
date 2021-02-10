#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
// int subsetMat[1000][1000];

// void subsetII(int *arr, int n,int int elem_so_far){
//     if(n==0){
//         return;
//     }
//     subsetMat[elem_so_far+1][0] = 1;
//     subsetMat[elem_so_far+1][1] = arr[0];
//     for(int i=1; i<elem_so_far; i++){
//         int col_ = subsetMat[i][0];
//         subsetMat[i+eslem_so_far+1][0] = subsetMat[i][0]+1;
//         for(int j=1; j<=col_; j++){
//             subsetMat[i+elem_so_far+1][j] = subsetMat[i][j];
//         }
//     }
//     subsetII(arr+1, n-1, 2*elem_so_far);
// }

void subsetII(int *arr,int n, vector<vector<int>> &res, vector<int> r){
    if(n==0){
        return;
    }
    r.push_back(arr[0]);
    res.push_back(r);
    subsetII(arr+1,n-1,res, r);
    r.pop_back();
    if(arr[1]!=arr[0] && n!=1){
        subsetII(arr+1,n-1, res, r);
    }
}


// int main(){
//     int arr[3] = {1,2,3};
//     vector<vector<int>> res;
//     vector<int> r;
//     subsetII(arr, 3, res, r);
//     for(int i=0; i<res.size(); i++){
//         for(int j=0; j<res[i].size(); j++){
//             cout << res[i][j] << " ";
//         }
//         cout <<endl;
//     }
// }
 // CPP program to generate power set in 
// lexicographic order. 

// str : Stores input string 
// n : Length of str. 
// curr : Stores current permutation 
// index : Index in current permutation, curr 
// void permuteRec(string str, int n, 
// 				int index = -1, string curr = "") 
// { 
// 	// base case 
// 	if (index == n) 
// 		return; 

// 	cout << curr << "\n"; 
// 	for (int i = index + 1; i < n; i++) { 

// 		curr += str[i]; 
// 		permuteRec(str, n, i, curr); 

// 		// backtracking 
// 		curr = curr.erase(curr.size() - 1); 
// 	} 
// 	return; 
// } 

// Generates power set in lexicographic 
// order. 
// void powerSet(string str) 
// { 
// 	sort(str.begin(), str.end()); 
// 	permuteRec(str, str.size()); 
// } 

// void lexiCombo(int *arr, int n, vector<vector<int>> &res, vector<int> r){
//     if(n==0){
//         return;
//     }

//     r.push_back(arr[0]);
//     res.push_back(r);
//     lexiCombo(arr+1, n-1, res, r);
//     r.pop_back();
//     if(arr[0]!=r[n-1]){
//         lexiCombo(arr+1, n-1, res, r);
//     }
//     else{
//         lexiCombo(arr+2, n-1, res, r);
//     }
// }
// vector<vector<int>> result;
// void backtrack(int *arr,vector<int> nums,int index)
// {
//     result.push_back(temp);
//     for(int i=index;i<nums.size();i++)
//     {
//         if(i!=index && nums[i]==nums[i-1])
//         continue;
//         temp.push_back(nums[i]);
//         backtrack(temp,nums,i+1);
//         temp.pop_back();
//     }
// }
// vector<vector<int>> result;
// void backtrack(vector<int> &temp,vector<int> nums,int index)
// {   
//     result.push_back(temp);
//     for(int i=index;i<nums.size();i++)
//     {
//         if(i!=index && nums[i]==nums[i-1])
//         continue;
//         temp.push_back(nums[i]);
//         backtrack(temp,nums,i+1);
//         temp.pop_back();
//     }
// }

// Driver code 
int main() 
{   
	vector<vector<int>> res;
    vector<int> r;
    int arr[4] = {1,2,2,4};
    sort(arr, arr+4);
    subsetII(arr, 4, res, r);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
} 
