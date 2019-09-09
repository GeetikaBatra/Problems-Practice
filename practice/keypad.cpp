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

int keyPadCombinations(int input, string output[]){
    if(input==0){
        output[0]="";
        return 1;
    }
    int countStrings = keyPadCombinations(input/10, output);
    int currentDigit = input%10;
         string currentKeys = keypadStrings(currentDigit);
    string temp[currentKeys.length()*countStrings];
    int k=0;
    for(int i=0; i<countStrings; i++){

        for(int j=0; j<currentKeys.length(); j++){
            temp[k++] = output[i]+currentKeys[j];
        }
    }

    for(int i=0; i<k ;i++){
        output[i] = temp[i];
    }
    return k;
}
int main(){

    int input;
    cin >> input;
    string* output = new string[1000];
    int count = keyPadCombinations(input, output);
    for(int i=0; i<count; i++){
        cout << output[i] << endl;
    }
}
