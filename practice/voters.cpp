#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

vector<int> getVoters(int arr[], int n){
    sort(arr, arr+n);
    vector<int> voters;
    sort(arr, arr+n);
	for(int i=0; i<n;){
	    int count = 0;
	    int j = i;
	    while(j<n && (arr[i] == arr[j])){
	        j++;
	    }
	    if(count>=2){
	        voters.push_back(arr[i]);
	    }
	    i = j;
	}
	return voters;
}
int main() {
	// your code goes here
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	int m = n1+n2+n3;
	int arr[m];
	for(int i=0; i<m; i++){
	    cin >> arr[i];
	}
	vector<int> voters = getVoters(arr, m);
    
	return 0;
}

