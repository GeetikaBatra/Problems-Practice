#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void replaceChar(char *str, char c1, char c2){
    if(str[0]=='\0'){
        return;
    }
    if(str[0]==c1){
        str[0]=c2;
    }
    replaceChar(str+1, c1, c2);
}

int main(){
    char str[100];
    cin >>str;
    char c1, c2;
    cin >>c1>>c2;
    replaceChar(str, c1, c2);  
    cout <<str<<endl;
}