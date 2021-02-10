#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int m, n1, n2;
        long long int min_;
        cin >> m >> n1 >> n2;
        long long int x = (m * (m + 1)) / 2;
        if(x<n1 && x<n2){
            min_ = x;
        }
        if(n1<n2){
             min_ = n1;
        }
        else{
            min_ = n2;
        }
        long long int left_stones = n1 + n2 - (2 * min_);
        cout << left_stones<< endl;
    }
}