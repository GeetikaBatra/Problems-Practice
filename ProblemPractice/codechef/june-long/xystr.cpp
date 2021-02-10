#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// #include <bits/stdc++.h>
// using namespace std;

int main(){
    int t;
    cin >>t;
    for(int i=0; i<t; i++){
        string str;
        cin >> str;
        int count=0;
        int j=0;
        while(j<str.length()-1){
        if(str[j]!=str[j+1]){
            j=j+2;
            count++;
        }
        j++;
        }
        cout << count <<endl;
    }
    return 0;
}