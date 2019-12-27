#include<bits/stdc++.h>
using namespace std;

int main(){
    int s=9,D=2;
    // cin>>s>>D;

    int arr[D];
    arr[0]=1;
    int i = D-1;
    s=s-1;
    while(s!=0){
        if(i<1){
            break;
        };
        if(s<9){
            arr[i] = s;
            s=0;
            i--;
            break;
        }
        arr[i] =9;
        s = s-9;
    }
    while(i>0){
        arr[i]=0;
        i--;
    }
    if(i==0 && s==0){
        for(int i=0; i<D; i++)
        {
            cout << arr[i];

        }
        cout << endl;
    }

}