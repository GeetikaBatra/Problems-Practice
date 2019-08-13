#include<bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int m = n1+n2+n3;
	int arr[m];
	for(int i=0; i<m; i++){
	    cin >> arr[i];
	}
	vector<int> result;
	sort(arr, arr+m);
	for(int i=0; i<m;){
	    int j=0;
	    while(j<m && (arr[i] == arr[j])){
	        j++;
	    }
	    if(j>=2){
	        result.push_back(arr[i]);
	    }
	    i = i + j;
	}
	cout << result.size() << endl;
	for(int i = 0; i<result.size(); i++){
	    cout << result[i] <<endl;
	}
	return 0;
}

