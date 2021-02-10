// #include "/Users/gbatra/ProblemPractice/stdc++.h"
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int *a = new int[n];
//         int *b = new int[m];
//         int sum_a = 0;
//         int sum_b = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             sum_a += a[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin >> b[i];
//             sum_b += b[i];
//         }

//         int swapCount = 0;

//         while (sum_a <= sum_b)
//         {

//             int max_ = INT_MIN;
//             int max_index = -1;
//             for (int i = 0; i < m; i++)
//             {
//                 if (max_ < b[i])
//                 {
//                     max_ = b[i];
//                     max_index = i;
//                 }
//             }

//             int min_ = INT_MAX;
//             int min_index = -1;
//             for (int i = 0; i < n; i++)
//             {
//                 if (min_ > a[i])
//                 {
//                     min_ = a[i];
//                     min_index = i;
//                 }
//             }
//             if (a[min_index] > b[max_index])
//             {
//                 break;
//             }
//             swapCount++;
//             sum_a = sum_a - a[min_index] + b[max_index];
//             sum_b = sum_b - b[max_index] + a[min_index];
//             Swap(a[min_index, b[max_index]]);
//         }
//         if (sum_a > sum_b)
//         {
//             cout << swapCount << endl;
//         }
//         else
//         {
//             cout << -1 << endl;
//         }
//     }
// }
#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
const int N = 1010;
const int M = 1010;
int n, m, a[N], b[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //    freopen("input2.txt","r",stdin);
    //    freopen("output2.txt","w",stdout);

    int qq;
    cin >> qq;

    for (; qq; qq--)
    {
        cin >> n >> m;

        int sum_a = 0;
        int sum_b = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum_a += a[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            sum_b += b[i];
        }

        while (sum_a <= sum_b)
        {
            int mn_a = int(1e9), loc_a = -1;
            int mx_b = -1, loc_b = -1;

            for (int i = 0; i < n; i++)
                if (a[i] < mn_a)
                {
                    mn_a = a[i];
                    loc_a = i;
                }

            for (int i = 0; i < m; i++)
                if (b[i] > mx_b)
                {
                    mx_b = b[i];
                    loc_b = i;
                }

            if (mn_a >= mx_b)
            {
                ans = -1;
                break;
            }

            ans++;

            swap(a[loc_a], b[loc_b]);

                sum_a -= mn_a;
                sum_a += mx_b;

                sum_b += mn_a;
                sum_b -= mx_b;
        }

        cout << ans << '\n';
    }

    return 0;
}