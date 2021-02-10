#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

void subseq(string s, vector<string> *s_arr, int *length_){
    if(s==""){
        s_arr.push_back("");
        *length_ = *length_+1;
    }
    subseq(s.substr(1), s_arr, length_);
    for(int i=0; i<*length_; i++){
        string temp_s = s[0] + s_arr[i];
        s_arr[*length_+1] = temp_s;
        *length_ = *length_+1;
    }
}

int main(){
    string s = "abcdef";
    vector<string> s_arr;
    int length_ = 0;

    subseq(s, s_arr, &length_);
    for(int i=0; i<length_; i++){
         cout <<s_arr[i]<<endl;
    }
}