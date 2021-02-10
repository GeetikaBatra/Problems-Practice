#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

string getKeys(int ch){
    if(ch==0){
        return "";
    }
    else if(ch==1){
        return "";
    }
    else if(ch==2){
        return "abc";
    }
    else if(ch==3){
        return "def";
    }
    else if(ch==4){
        return "ghi";
    }
    else if(ch==5){
        return "jkl";
    }
    else if(ch==6){
        return "mno";
    }
    else if(ch==7){
        return "pqrs";
    }
    else if(ch==8){
        return "tuv";
    }
    else if(ch==9){
        return "wxyz";
    }
    return "";
}

void printComb(int num, string op){
    if(num==0){
        cout << op << endl;
    }
    int rem = num%10;
    int curr = num/10;

    string remKeys = getKeys(rem);
    for(int i=0; i<remKeys.length(); i++){
        printComb(curr, remKeys[i] + op);
    }
}

int main(){
    int num = 23;
    printComb(num, "");
}