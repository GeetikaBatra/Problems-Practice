// #include<bits/stdc++.h>
// using namespace std;

// int coinChange(int n, int* d, int numD, int output){
//     if(n==0){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }
//     if(output[n][numD]>-1){
//         return output[n][numD];
//     }

//     int first=coin_change(n-d[0],d,numD);
//     int second=coin_change(n, d+1, numD-1);
//     output[n][numD] = first+second;
//     return first+second;
// }
// int main(){
//     int d[3] = {1,2,3};
//     int sum=6;
//     int** dp[sum+1][4];
//     memset(dp, -1, sizeof(int));
//     coinChange(sum,d, 3, dp);
// }
#include<bits/stdc++.h>
using namespace std;
int coin_change3(int sum, int* d, int numD,vector< vector<int> > op ){

    for(int i=1; i<=numD; i++){
        for(int j=1;j<=sum;j++){
            op[i][j]=0;
            if((j-d[i-1])>=0){
                op[i][j]=op[i][j-d[i-1]];
            }
            op[i][j]+=op[i-1][j];
        }
    }
    
    return op[numD][sum];
}
int coin_change2(int sum, int* d, int numD,  vector< vector<int> > op){
    //DP with recurison
    // cout << sum << numD << endl;
    if(sum==0){
        return 1;
    }
    if(numD==0){
        return 0;
    }
    if(sum<0){
        return 0;
    }
    for(int i=0;i<numD;i++){
        for(int j=0;j<sum;j++){
            cout<<op[i][j];
        }
        cout<<endl;
    }
    if(op[numD][sum]!=-1){
        return op[numD][sum];
    }
    int first = coin_change2(sum-d[0], d, numD, op);
    int second = coin_change2(sum, d+1, numD-1, op);
    
    op[numD][sum]=first+second;
    return first+second;
}
int coin_change(int sum, int* d, int numD){
    //recursive method
    if(sum==0){
        return 1;
    }
    if(numD==0){
        return 0;
    }
    if(sum<0){
        return 0;
    }

    int first = coin_change(sum-d[0], d, numD);
    int second = coin_change(sum, d+1, numD-1);
    return first+second;
}

int main(){
    int numD, sum;
    cin >> numD;
    int dim[numD];
    for(int i=0; i<numD; i++){
        cin>>dim[i];
    }
    cin>>sum;
    vector< vector<int> > op;
    for(int i=0;i<numD+1;i++){
        vector<int> col;
        for(int j=0;j<=sum;j++)
        {
            if(i==0){
                col.push_back(0);
            }
            else{
                col.push_back(-1);
            }
            
        }
        op.push_back(col);
    }
    for(int i=1;i<numD+1;i++){
        op[i][0]=1;   
    }

    cout<<coin_change3(sum,dim,numD,op)<<endl;
}