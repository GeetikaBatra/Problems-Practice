#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;

bool isValid(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        if (str[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return (cnt == 0);
}
bool checkParanth(char c)
{
    return ((c == '(') || (c == ')'));
}
void removeInvalidParanthesis(string str)
{
    if (str.empty())
        return;
    set<string> visited;
    queue<string> q;

    q.push(str);
    visited.insert(str);
    while (!q.empty())
    {
        string temp = q.front();
        q.pop();
        if (isValid(temp))
        {
            cout << temp << endl;
            continue;
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (!checkParanth(str[i]))
                continue;
            string newtemp = str.substr(0, i) + str.substr(i + 1);
            if (visited.find(newtemp) == visited.end())
            {
                q.push(newtemp);
                visited.insert(newtemp);
            }
        }
    }
}
int main()
{
    string s = "()())()";
    removeInvalidParanthesis(s);
}