
#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
void test_func(vector<string> &s){
    cout << s[0][1]<<endl;
}
int main(){
    string s= "geetika";
    vector<string> vec;
    vec.push_back(s);
    test_func(vec);
    cout << vec[0][1]<<endl;
}