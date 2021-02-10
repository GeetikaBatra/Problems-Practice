#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

bool checkAB(string s, int l){
    if(s.length()==0){
        return true;
    }
    if(s.length()==l && s[0] !='a'){
        return false;
    }
    if(s[0]=='a'){
        if(s[1]!='\0' || (s[1]!='b') || (s[2]!='b')){
            return false;
        }
    }
    if(s[0]=='b'){
        if(s[1]!='\0' || s[1]!='b'){
            return false;
        }
    }
    return checkAB(s.substr(1), l);
}


int main(){
    string s = "a";
    cout << checkAB(s, 1)<< endl;

}