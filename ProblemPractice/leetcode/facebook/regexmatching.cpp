#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;

bool DP[10000][10000];

bool isMatch(string s, string reg)
{
    int m = 0;
    int n = 0;
    for (int i = 0; i < = s.length(); i++)
    {
        for (int j = 0; j <= reg.length(); j++)
        {
            DP[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= reg.length(); j++)
        {
            if (s[m] == reg[n] || reg[n] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (reg[m] == '*')
            {
                if(s[m])
            }
        }
    }
    return false;
}
int main()
{
    string s = "mississippi";
    string reg = "mis*is*p*.";
    cout << isMatch(s, reg) << endl;
}