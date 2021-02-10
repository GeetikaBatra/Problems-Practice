#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll K, N;
        cin >> N >> K;
        vector<ll> w(N);
        for (int i = 0; i < N; i++)
        {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        ll max_diff1 = 0;
        ll sum1 = 0;
        ll sum2 = 0;
        for (int i = 0; i < N; i++)
        {
            if (i < K)
            {
                sum1 += w[i];
            }
            else
            {
                sum2 += w[i];
            }
        }
        max_diff1 = abs(sum2 - sum1);
        sum2 = 0;
        sum1 = 0;
        for (int i = 0; i < N; i++)
        {
            if (i < N - K)
            {
                sum1 += w[i];
            }
            else
            {
                sum2 += w[i];
            }
        }
        ll max_diff2 = abs(sum2 - sum1);
        cout << max(max_diff1, max_diff2) << endl;
    }
}