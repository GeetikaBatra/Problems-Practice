#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int max_div = 1;

    for (int i = 1; i <= 10; i++)
    {
        if (N % i == 0)
        {
            max_div = max(max_div, i);
        }
    }
    cout << max_div << endl;
}