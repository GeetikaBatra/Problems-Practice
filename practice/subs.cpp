#include<bits/stdc++.h>
using namespace std;

int subs(string input, string output[]){

    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallsub = input.substr(1);
    int countSubs = subs(smallsub, output);
    for(int i=0; i<countSubs; i++){
        output[i+countSubs] = input[0] + output[i];
    }
    return 2*countSubs;
}

int main(){

    string input;
    cin >> input;
    string* output = new string[1000];
    int count = subs(input, output);
    for(int i=0; i<count; i++){
        cout << output[i] << endl;
    }
}
