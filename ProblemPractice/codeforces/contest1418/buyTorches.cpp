//#include "/Users/gbatra/ProblemPractice/stdc++.h"
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int64_t t;
    cin >>t;
    while(t--){
        int64_t x, y,k;
        cin>>x>>y>>k;
        cout << ((k*(y+1)+x-3)/(x-1))+k<<endl;
    }
}