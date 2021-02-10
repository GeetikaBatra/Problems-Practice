#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void removeDuplicate(char *input){
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==input[1]){
        int i=1;
        for(; input[i]!='\0'; i++){
            input[i-1] = input[i];
        }
        input[i-1] = input[i];
        removeDuplicate(input);
    }
    else{
        removeDuplicate(input+1);
    }
    
}

int main(){ 
    char input[100];
    cin >> input;
    removeDuplicate(input);
    cout <<input<<endl;
}