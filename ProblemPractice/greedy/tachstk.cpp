#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
int main()
{
    int N;
    int D;
    cin >> N >> D;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int numPairs = 0;
    for (int i = 1; i < N;)
    {
        if (arr[i] - arr[i - 1] <= D)
        {
            numPairs++;
            i = i + 2;
        }
        else
        {
            i++;
        }
    }
    cout << numPairs << endl;
}