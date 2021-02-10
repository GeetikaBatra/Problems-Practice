#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
#define ll long long
void check(string s, string p, int n)
{
    ll flag_set = 0;
    for (int i = 0; i < n; i++)
    {
        flag_set += int(s[i]) - int(p[i]);
        if (flag_set < 0)
        {
            cout << "No" << endl;
        }
    }
    if (flag_set != 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        string p;
        cin >> s;
        cin >> p;
        check(s, p, n);
    }
}