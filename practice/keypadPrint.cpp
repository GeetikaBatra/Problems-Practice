#include<bits/stdc++.h>
using namespace std;

void keyPadPrint(string input, string output){

    if(input.empty()){
        cout << output << endl;
	return;
    }

    keyPadPrint(input.substr(1), output);
    keyPadPrint(input.substr(1), output  + input[0]);


}

int main(){

    string input;
    cin >> input;
    keyPadPrint(input, "");
}
