#include<bits/stdc++.h>
using namespace std;

string keypadStrings(int digit){
    if(digit==2){
        return "abc";
    }
    else if(digit==3){
        return "def";
    }
    else if(digit==4){
        return "ghi";
    }
    else if(digit==5){
        return "jkl";
    }
    else if(digit==6){
        return "mno";
    }
    else if(digit==7){
        return "pqrs";
    }
    else if(digit==8){
        return "tuv";
    }
    else if(digit==9){
        return "wxyz";
    }
    else{
        return "";
    }
}
void keyPadCombinations(int input, string output){

    if(input==0){
        cout << output << endl;
        return;
    }
    int getDigit = input%10;

    string keys = keypadStrings(getDigit);
    cout << keys << endl;
    for(int i=0; i<keys.length(); i++){
        keyPadCombinations(input/10, keys[i] + output);
    }
}

int main(){
    int input;
    cin >> input;

    keyPadCombinations(input, "");
}
