#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// int minCostJobRec(int arr[4][4], int p, int n, int mask)
// {
//     if (p < 0)
//     {
//         return 0;
//     }
//     int min_ = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if (!(mask & (1 << i)))
//         {
//             min_ = min(min_, arr[p][i] + minCostJobRec(arr, p - 1, n, mask | (1 << i)));
//         }
//     }
//     return min_;
// }

// int DP[1001];
// int minCostJobDpRec(int arr[4][4], int p, int n, int mask)
// {
//     if (p < 0)
//     {
//         return 0;
//     }
//     int min_ = INT_MAX;
//     if (DP[mask])
//     {
//         return DP[mask];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!(mask & (1 << i)))
//         {
//             min_ = min(min_, arr[p][i] + minCostJobRec(arr, p - 1, n, mask | (1 << i)));
//         }
//     }
//     DP[mask] = min_;
//     return min_;
// }
int dp[1001];
int count_set_bits(int mask, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            count++;
        }
    }
    return count;
}
int minCostIter(int arr[4][4], int n)
{

    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int x = count_set_bits(mask, n);

        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + arr[x][j]);
            }
        }
    }
    // for (int i = 0; i < (1 << 4) - 1; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    return dp[(1 << n) - 1];
}
int main()
{
    int arr[4][4] = {
        {10, 2, 6, 5},
        {1, 15, 12, 8},
        {7, 8, 9, 3},
        {15, 13, 4, 10},
    };
    // memset(dp, INT_MAX, sizeof dp);
    // memset(DP, 0, sizeof(int));

    // for (int i = 0; i < (1 << 4) - 1; i++)
    // {
    //     dp[i] = INT_MAX;
    // }
    cout << minCostIter(arr, 4) << endl;
    // cout << minCostJobDpRec(arr, 3, 4, 0) << endl;
    // cout << minCost(arr, 4, 0, 0, INT_MAX) << endl;
}