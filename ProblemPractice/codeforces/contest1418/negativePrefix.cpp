// #include "/Users/gbatra/ProblemPractice/stdc++.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >>T;
    while(T--){
        int n;
        cin >>n;
        int *a = new int[n];
        int *b = new int[n];
        vector<int> c;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >>b[i];
            if(!b[i]){
                c.push_back(a[i]);
            }
        }
        sort(c.begin(), c.end(), std::greater<int>());
        int k=0;
        for(int i=0; i<n; i++){
            if(b[i]){
                cout << a[i] << ' ';
                
            }
            else{
                cout << c[k]<<' ';
                k++;
            }
            
        }
    }
}