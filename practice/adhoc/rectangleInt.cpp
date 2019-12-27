#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max_x=0;
    int* height = new int[500000000+2]();
    memset(height, 0, sizeof(int)*(50000000+2));
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        height[x/2]=y;
        if(height[x/2]<y){
            height[x/2]=y;
        }
        if((x/2)>max_x){
        
            max_x=x/2;
        }
    }
    
    for(int i = max_x; i>=0; i--){
        if(height[i]<height[i+1]){
            height[i] = height[i+1];

        }
    }
    long area = 0;
    for(int i=max_x; i>0; i--){
        area+=2*height[i];
    }
    cout << area << endl;
}