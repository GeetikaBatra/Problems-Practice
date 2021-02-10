#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n;
        cin >> k;
        int arr[n];
        long long sum_ = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum_ += arr[i];
        }
        int rem_ = sum_ % k;
        if (rem_ == 0)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
}