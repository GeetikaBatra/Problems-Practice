#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;

int count_ = 0;

bool checkPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//this gives all posible substrings which could be palindrome
// ans is a, a, aa, b
// but we want [[a,a,b],[aa,b]]
void palindPart(string s, string r, vector<string> &res)
{
    if (s.length() == 0)
    {
        return;
    }

    r = r + s[0];
    if (checkPalindrome(r))
    {
        res.push_back(r);
    }
    palindPart(s.substr(1), r, res);
    r.erase(r.size() - 1);
    if (r == " ")
    {
        palindPart(s.substr(1), r, res);
    }
}

void palindPart2(string s, int part, vector<string> r, vector<vector<string>> &res)
{
    if (s.length() == 1)
    {
        r.push_back(s);
        res.push_back(r);
        return;
    }
    checkPalindrome(s.substr(0, part + 1));
    for (int i = part + 1; i < s.length(); i++)
    {
        {
            r.push_back(s.substr(0, i));
            palindPart2(s.substr(i), i, r, res);
            r.pop_back();
        }
    }
}

int main()
{
    string s = "aab";
    vector<vector<string>> res;
    vector<string> r;
    palindPart2(s, 0, r, res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
    }
}