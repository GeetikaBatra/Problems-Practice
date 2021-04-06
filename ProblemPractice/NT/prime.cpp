#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;

bool checkPrime(int n)
{
    int count = 0;

    for (int i = 1; i * i < n; i++)
    {
        if (i * i == n)
        {
            count += 1;
        }
        if ((n % i) == 0)
        {
            count += 2;
        }
    }
    if (count == 2)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (checkPrime(n))
        {
            count++;
        }
    }
    cout << count << endl;
}