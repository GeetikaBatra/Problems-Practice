#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start, finish;
};
Activity arr[100000000];
bool activityCompare(Activity A1, Activity A2){
    return (A1.finish<A2.finish);
}

int printActivity(Activity *arr, int n){
    sort(arr, arr+n, activityCompare);

    int i=0;
    int count = 1;
    for(int j=0;j<n;j++){
        if(arr[j].start>arr[i].finish){
            count++;
            cout << count << endl;
            cout << arr[j].start << arr[j].finish << endl;
            i=j;
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    Activity arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].start;
        cin>>arr[i].finish;
    }    
    cout << printActivity(arr, n)<<endl;


}