//https://www.spoj.com/problems/XMAX/

#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;



//This question asks for the max xor out of any subset
//My idea is to find all the subsets which could give me back the 


int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    int DP[10004];
    int max_so_far=INT_MIN;
    DP[0]=0;
    int elements_so_far = 1;
    while(elements_so_far!=(1<<n)){
        for(int i=0; i<elements_so_far; i++){
            DP[i+elements_so_far] = DP[i]^arr[0];
            max_so_far = max(max_so_far, DP[i+elements_so_far]);
            
        }
        arr= arr+1;
        elements_so_far = 2*elements_so_far;
        
    }
    cout <<max_so_far<<endl;

}