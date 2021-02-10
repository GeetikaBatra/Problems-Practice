#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

string getkeys(int ch){
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
int getcomb(int num, string *op){
    if(num==0){
        return 1;
    }
    int rem = num%10;
    int cur = num/10;
    int numstr = getcomb(cur, op);
    int tempC = 0;
    string subst = getkeys(rem);
    string *newop = new string[numstr*subst.length()];
    for(int i=0; i<numstr; i++){
        for(int j=0; j<subst.length(); j++){
            newop[tempC] = op[i] + subst[j] ;
            tempC++;
        }
    }
    for(int i=0; i<tempC; i++){
        op[i] = newop[i];
    }
    return tempC;
}
int main(){
    int num = 23;
    string *op = new string[100000];
    int numstr = getcomb(num, op);
    for(int i=0; i<numstr; i++){
        cout << op[i] << endl;
    }
}