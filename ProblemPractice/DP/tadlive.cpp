#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

// recursive solution
// complexity is 2^n
void tadlive(int n, int i, int *a, int *b, int &ans, int x, int y, int aorder, int border, int total)
{
    if (i == n)
    {
        if (aorder <= x && border <= y)
        {
            ans = max(ans, total);
        }
        return;
    }
    tadlive(n, i + 1, a, b, ans, x, y, aorder + 1, border, total + a[i]);
    tadlive(n, i + 1, a, b, ans, x, y, aorder, border + 1, total + b[i]);
}

// bit mask
// complexity is o(2^n * n)
void tadliveBitMask(int n, int *a, int *b, int x, int y)
{
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int andyorders = 0;
        int boborders = 0;
        int totalMoney = 0;
        for (int i = 0; i < n; i++)
        {

            if (mask & (1 << i))
            {
                andyorders++;
                totalMoney += a[i];
            }
            else
            {
                boborders++;
                totalMoney += b[i];
            }
        }
        if (andyorders <= x && boborders <= y)
        {

            ans = max(ans, totalMoney);
        }
    }
    cout << ans << endl;
}

//talive interval solution
//complexity is nlogn + n
struct interval
{
    int s, e;
};
bool compare(interval c1, interval c2)
{
    int k = c1.s - c1.e;
    int l = c2.s - c2.e;
    return abs(k) > abs(l);
}

void tadliveInterval(interval *c, int n, int x, int y)
{
    int profit = 0;
    sort(c, c + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (c[i].s > c[i].e)
        {
            if (x != 0)
            {
                profit += c[i].s;
                x--;
            }
            else
            {
                profit += c[i].e;
                y--;
            }
        }
        else if (c[i].s < c[i].e)
        {
            if (y != 0)
            {
                profit += c[i].e;
                y--;
            }
            else
            {
                profit += c[i].s;
                x--;
            }
        }
        else if (c[i].s == c[i].e)
        {
            if (x != 0)
            {
                profit += c[i].s;
                x--;
            }
            else
            {
                profit += c[i].e;
                y--;
            }
        }
    }

    cout << profit << endl;
}

//DP solution single

void tadliveDP(interval *c, int n, int x, int y)
{
    int dp[1001];
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (x != 0 && y != 0)
        {
            dp[i + 1] = dp[i] + max(c[i].s, c[i].e);
        }
        if (x == 0)
        {
            dp[i + 1] = dp[i] + c[i].e;
        }
        if (y == 0)
        {
            dp[i + 1] = dp[i] + c[i].s;
        }
        x--;
        y--;
    }

    cout << dp[n] << endl;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    // int *a = new int[n];
    // int *b = new int[n];
    interval *arr = new interval[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].s;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].e;
    }
    // tadliveInterval(arr, n, x, y);
    tadliveDP(arr, n, x, y);
    // int ans = INT_MIN;
    // tadlive(n, 0, a, b, ans, x, y, 0, 0, 0);
    // tadliveBitMask(n, a, b, x, y);
    // cout << ans << endl;
}
