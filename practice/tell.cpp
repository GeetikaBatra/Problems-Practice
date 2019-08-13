#include<bits/stdc++.h>
using namespace std;
struct Info{
    string name;
    int m1;
    int m2;
    int m3;
    int roll_no;
};

bool compare(Info i1, Info i2){
   int  marks_1 = i1.m1 + i1.m2 + i1.m3;
   int marks_2 = i2.m1 + i2.m2 + i2.m3;
    
    if(marks_1>marks_2){
        return true;
    }
    else if(marks_1<marks_2){
        return false;
    }
//    else{
//        return i1.roll_no < i2.roll_no;
//    }
    
}
int main()
{
    int n;
    cin >> n;
    
    Info arr[n];
    for(int i=0; i<n; i++){
        Info elem;
        cin >> elem.name >> elem.m1 >> elem.m2 >> elem.m3;
        
        arr[i] = elem;
        
    }
    sort(arr, arr+n, compare);
    
    for(int i=0; i<n; i++){
        cout << i+1  << " " <<  arr[i].name << endl;
    }
	return 0;
}

