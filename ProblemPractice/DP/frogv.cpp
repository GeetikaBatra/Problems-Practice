#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

struct frogv
{
    int id, x;
};
bool comp(frogv f1, frogv f2)
{
    return f1.x < f2.x;
}
int DP[100001];
int main()
{
    int N, k, p;
    cin >> N >> k >> p;
    frogv *frogs = new frogv[N];
    for (int i = 0; i < N; i++)
    {
        int x;
        frogv p;
        cin >> p.x;
        p.id = i;
        frogs[i] = p;
    }
    sort(frogs, frogs + N, comp);
    DP[frogs[0].id] = frogs[0].x;
    for (int i = 1; i < N; i++)
    {
        if ((frogs[i].x - frogs[i - 1].x) <= k)
        {
            DP[frogs[i].id] = DP[frogs[i - 1].id];
        }
        else
        {
            DP[frogs[i].id] = frogs[i].x - k;
        }
    }
    for (int i = 0; i < p; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        if (DP[p1 - 1] == DP[p2 - 1])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}