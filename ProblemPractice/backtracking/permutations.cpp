#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;


int perm(string s, int l, int r, int k){
        if(l==r){
            k=k-1;
            if(k==0){
                cout <<s<< endl;
            }
            return k;
        }
        for(int i=l; i<=r; i++){
            swap(s[l], s[i]);
            k = perm(s, l+1, r, k);

        }
        return k;

}

int main(){

    string s = "123";
    int k=3;
    perm(s, 0, s.length()-1, k);
}