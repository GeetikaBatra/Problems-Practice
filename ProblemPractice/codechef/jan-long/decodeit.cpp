#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int main()
{
    char dp[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    int t;
    cin >> t;
    while (t--)
    {
        int l;
        cin >> l;
        string s;
        cin >> s;
        int count = 0;
        string res = "";
        int st = 0, end = 15;
        int i = 0;
        while (i != l)
        {

            if (s[i] == '1')
            {
                st = ((st + end) / 2) + 1;
            }
            else
            {
                end = ((st + end) / 2);
            }
            count++;
            i++;
            if (count == 4)
            {
                res = res + (dp[(st + end) / 2]);
                st = 0;
                end = 15;
                count = 0;
            }
        }
        cout << res << endl;
    }
}