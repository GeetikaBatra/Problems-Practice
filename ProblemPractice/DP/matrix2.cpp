#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;
#define ll long long

// int grid[10001][10001];
int main()
{
    int N, M;
    cin >> N >> M;
    // int **grid = new int *[N];
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            int x = str[j] - '0';
            v.pb(x);
        }
        grid.pb(v);
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j]) + 1;
            }
        }
    }
    ll count_all = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            count_all += grid[i][j];
        }
    }
    cout << count_all << endl;
}