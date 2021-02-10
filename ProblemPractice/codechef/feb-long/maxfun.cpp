#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

typedef long long int ll;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        ll *arr = new ll[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + N);
        ll x = arr[0];
        ll y = arr[1];
        ll z = arr[N - 1];
        ll sum_ = abs(x - y) + abs(y - z) + abs(z - x);
        cout << sum_ << endl;
    }
}