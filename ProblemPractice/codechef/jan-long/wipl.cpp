#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int h[1001];
int DP[1001][1001];

//greedy
int wiplRecursive(int N, int K, int m_height, int t_height, int m_boxes, int t_boxes)
{

    if (m_height >= K && t_height >= K && N >= 0)
    {
        return m_boxes + t_boxes;
    }
    if (N < 0)
    {
        return -1;
    }
    int mark_order = wiplRecursive(N - 1, K, m_height + h[N - 1], t_height, m_boxes + 1, t_boxes);
    int tracy_order = wiplRecursive(N - 1, K, m_height, t_height + h[N - 1], m_boxes, t_boxes + 1);
    if (mark_order != -1 && tracy_order != -1)
    {
        return min(mark_order, tracy_order);
    }
    else if (mark_order == -1)
    {
        return tracy_order;
    }
    else if (tracy_order == -1)
    {
        return mark_order;
    }
    return -1;
}
int wipBitMAsk(int N, int K)
{
    
}
// int wiplRecursiveDP(int N, int K)
// {
//     int ans = INT_MAX;
//     int m_min = INT_MAX;
//     int t_min = INT_MAX;
//     for (int mask = 0; mask < (1 << N); mask++)
//     {
//         int m_height = 0;
//         int t_height = 0;
//         int m_boxes = 0;
//         int t_boxes = 0;

//         for (int i = 0; i < N; i++)
//         {

//             if (mask & (1 << i))
//             {
//                 m_height = m_height + h[i];
//                 m_boxes++;
//             }

//             if (m_height >= K)
//             {
//                 m_min = min(m_min, m_boxes);
//                 break;
//             }
//         }
//         for (int i = 0; i < N; i++)
//         {

//             if (!(mask & (1 << i)))
//             {
//                 t_height = t_height + h[i];
//                 t_boxes++;
//             }

//             if (t_height >= K)
//             {
//                 t_min = min(t_min, t_boxes);
//                 break;
//             }
//         }
//     }
//     if (m_min > 0 && t_min > 0)
//     {
//         return (m_min + t_min);
//     }
//     return -1;
// }
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;

        for (int i = 0; i < N; i++)
        {
            cin >> h[i];
        }
        // cout << wiplRecursive(N, K, 0, 0, 0, 0) << endl;
        cout << wiplRecursiveDP(N, K) << endl;
    }
}