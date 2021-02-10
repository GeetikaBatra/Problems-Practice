#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int printSubseq(string s, string *op){
    if(s.length()==0){
        op[0] = "";
        return 1;
    }
    int substrs = printSubseq(s.substr(1), op);
    for(int i=0; i<substrs; i++){
        op[substrs+i] = s[0] + op[i];
    }
    return substrs*2;
}

int main(){
    string s = "abc";
    string *output = new string[1<<s.length()];
    int numstr =  printSubseq(s, output);
    for(int i=0; i<numstr; i++){
        cout << output[i] << endl;
    }
}