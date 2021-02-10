#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int dp[101][10001];

// This is recursive solution
// void xorsub(int *arr, int idx, int n, int currXor)
// {
//     if (idx == n)
//     {
//         dp[n - 1][currXor] = 1;
//         return;
//     }
//     if (dp[idx][currXor] != 0)
//     {
//         return;
//     }
//     dp[idx][currXor] = 1;
//     xorsub(arr + 1, idx, n, currXor);
//     xorsub(arr + 1, idx, n, currXor ^ arr[0]);
//     return;
// }

//iterative
void xorsubIter(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 1024; j++)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j ^ arr[i]];
        }
    }
}

int main()
{
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        xorsubIter(arr, n);
        int res = 0;
        for (int j = 0; j <= 1024; j++)
        {
            if (dp[n - 1][j] == 1)
            {
                res = max(res, j ^ k);
            }
        }
        cout << res << endl;
    }
}