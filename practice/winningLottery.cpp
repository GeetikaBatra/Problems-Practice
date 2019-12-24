#include<bits/stdc++.h>
using namespace std;

vector<int> number ;

bool findEmpty(int &digit, int n){
    for(int i=0; i<n; i++){
        if(number[i]==-1){
            digit=i;
            return true;
        }
    }
    return false;
}
void winningLottery(int n, int sum, int &min){
    int digit;
    if(!findEmpty(digit,n)){
        int s_=0;
        for(int i=0; i<n; i++){
            s_+=number[i];
        }
        if(s_==sum){
            //print number;
            int num = number[0];
            for(int i=1; i<n; i++){
                num=num+(number[i]*pow(10,i));
            }
            if(min>num){
                min = num;
            }
            return;
        }
        return;
    }
    for(int i=1; i<10; i++){
        number[digit] = i;
        winningLottery(n, sum, min);
        number[digit] = -1;
    }
    return;
}

int main(){
    int s,n;
    cin>>s>>n;
    int min=INT_MAX;
    for(int i=0; i<n; i++){
        number.push_back(-1);
    }
    winningLottery(n,s,min);
    cout<<min<<endl;
}
