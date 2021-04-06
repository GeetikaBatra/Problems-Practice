#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;

void addBinary(string s1, string s2)
{
    int carry = 0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    string res = "";
    while (i >= 0 || j >= 0)
    {
        int sum = 0;
        if (i >= 0)
        {
            sum += s1[i] - '0';
            // cout << sum << endl;
            i--;
        }
        if (j >= 0)
        {
            sum += s2[j] - '0';
            // cout << sum << endl;

            j--;
        }
        // cout << sum << endl;
        sum = sum + carry;
        res = (char)((sum % 2) + '0') + res;
        carry = sum / 2;
    }
    if (carry)
    {
        res = (char)((carry) + '0') + res;
    }
    cout << res << endl;
}
int main()
{
    string s1 = "11";
    string s2 = "1";
    addBinary(s1, s2);
}