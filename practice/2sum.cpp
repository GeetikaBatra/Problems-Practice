#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { 
        int i=0;
        int j=nums.size()-1;
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        sort(nums.begin(), nums.end());
        while(i<=j){
            if(i==j){
                //assuming numbers in vector are posittive
                return result;
            }
            if((nums[i]+ nums[j])>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                result.push_back(i);
                result.push_back(j);
            }
        }
        return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int target;
    cin >> target;
    vector<int> result = twoSum(arr, target);
    cout << result[0] << result[1] << endl;
}

