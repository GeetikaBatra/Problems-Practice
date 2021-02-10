#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main()
{
    int N, S, D;
    cin >> N >> S >> D;
    int flag    =0;
    for(int i=0; i<N; i++){
        int X, Y;
        cin>> X>> Y;
        if(X<S && Y>D){
            flag=1;
            cout << "Yes"<< endl;
            return 0;
        }
    }
    cout << "No"<< endl;
    
   
}