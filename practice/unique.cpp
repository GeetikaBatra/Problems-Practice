#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

int FindUnique(int* arr, int size){
    unordered_map<int,int> count_map;

    for(int i=0; i<size; i++){
        if(count_map.find(arr[i])==count_map.end()){
            count_map[arr[i]]=1;
        }
        else {
            count_map[arr[i]]++;

        }
    }
    for(int i=0; i<size; i++){
        if(count_map[arr[i]]<2){
            return arr[i];
        }
    }
}
int main(){
    int size;
    cin >> size;
    int arr[size];

    for(int i=0; i<size; i++){
        cin >> arr[i];
	}       
	cout << FindUnique(arr, size) << endl;
}

