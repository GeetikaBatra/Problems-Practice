#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int calhour(string mytime, int t)
{
    int mh;
    mh = 10 * (mytime[0 + t] - '0') + 1 * (mytime[1 + t] - '0');
    if (mytime[6 + t] == 'P')
    {
        if (mh != 12)
            mh += 12;
    }
    if (mytime[6 + t] == 'A')
    {
        if (mh == 12)
            mh -= 12;
    }
    return mh;
}
int calmin(string mytime, int t)
{
    int mm;
    mm = 10 * (mytime[3 + t] - '0') + (mytime[4 + t] - '0');
    return mm;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        string mytime;
        cin >> mytime;
        int mhour = calhour(mytime, 0);
        int mmin = calmin(mytime, 0);
        long long n;
        cin >> n;
        string res = "";
        while (n--)
        {
            string friendtimerange;
            cin >> friendtimerange;
            int fsh = calhour(friendtimerange, 0);
            int fsm = calmin(friendtimerange, 0);
            int feh = calhour(friendtimerange, 9);
            int fem = calmin(friendtimerange, 9);

            if ((fsh > mhour) || (feh < mhour))
            {
                res.push_back('0');
            }
            else if (fsh == mhour && fsm > mmin)
                res.push_back('0');
            else if (feh == mhour && fem < mmin)
                res.push_back('0');
            else
                res.push_back('1');
        }
        cout << res << "\n";
    }
    return 0;
}