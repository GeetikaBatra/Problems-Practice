#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;
        int sum_ = 0;
        for (int i = 0; i < n; i++)
        {
            int pb;
            cin >> pb;
            sum_ += pb;
        }

        int res = 0;
        if (sum_ / k > d)
        {
            res = d;
        }
        else
        {
            res = sum_ / k;
        }

        cout << res << endl;
    }
}