#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int rayX[1001][1001];
int rayY[1001][1001];
void grid(int n, vector<string> &input)
{
    memset(rayX, 0, sizeof rayX);
    memset(rayY, 0, sizeof rayX);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (input[i][j] == '.')
            {
                rayX[i][j] = (j != n - 1) ? rayX[i][j + 1] : 1;
            }
            else
            {
                rayX[i][j] = 0;
            }
            if (input[j][i] == '.')
            {
                rayY[j][i] = (j != n - 1) ? rayY[j + 1][i] : 1;
            }
            else
            {
                rayY[j][i] = 0;
            }
        }
    }
    int sum_ = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rayX[i][j] == 1 && rayY[i][j] == 1)
            {
                sum_ += 1;
            }
        }
    }
    cout << sum_ << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> input;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            input.push_back(s);
        }
        grid(n, input);
    }
}