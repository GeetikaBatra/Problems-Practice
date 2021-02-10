#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void printSubstr(string input, string output){
    if(input==""){
        cout << output << endl;
        return;
    }
    printSubstr(input.substr(1), output);
    printSubstr(input.substr(1), output + input[0];);
    return;
}

int main(){
    printSubstr("abc", "");
}