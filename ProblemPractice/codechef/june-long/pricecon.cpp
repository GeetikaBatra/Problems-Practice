#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
// #include <bits/stdc++.h>
// using namespace std;


int main(){
    int t; 
    cin >> t;
    // std::vector<int> op ;
    for(int i=0; i<t; i++){
        int diff=0;
        int n,k;
        cin>>n>>k;
        // vector<int> arr;
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            if(temp>k){
                diff+=temp-k;
            }
        }
       cout <<diff<<endl;
    }
    
}