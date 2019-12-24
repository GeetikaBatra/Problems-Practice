#include<bits/stdc++.h>
using namespace std;

vector<int> factor;

int findfactor(int n, int &max){
    for(int i=2; i<n/2; i++){
        while(n%i==0){
        n=n/2;
        factor.push_back(i);
        }
        max=i;
        i++;
    }  
}
int main(){
    int x;
    cin>>x;
    int max=1;
    factor.push_back(1);
    findfactor(x, max);
    factor.push_back(x-max);
    cout<<factor.size()<<endl;
}