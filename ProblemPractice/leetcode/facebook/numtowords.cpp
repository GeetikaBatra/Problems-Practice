#include "/Users/gbatra/Problems-Practice/ProblemPractice/stdc++.h"
using namespace std;

const int billion = 1000000000;
const int million = 1000000;
const int thousand = 1000;
const int hundred = 100;
const int ten = 10;

const string units[4] = {
    "Billion",
    "Million",
    "Thousand",
    "Hundred"};

const string tens[8] = {
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"};

const string tens2[10] = {
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
};
const string nums[10] = {
    "Zero",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine"};

//hundreds
void process(int q, string &result)
{
    int q1 = q / hundred;
    int r1 = q % hundred;
    if (q1 > 0)
    {
        result += units[3];
        result += " ";
    }
    int q2, r2;
    if (r1 > 0)
    {
        q2 = r1 / ten;
        r2 = r1 % ten;
        if (q2 == 1)
        {
            result += tens2[r1];
            result += " ";
        }
        else
        {
            result += tens[q2 - 2];
            result += " ";
        }
    }

    if (r2 > 0 && q2 != 1)
    {
        result += nums[r2];
        result += " ";
    }
}

//big numbers
void numToWords(int num)
{
    string result = "";
    int q1 = num / billion;
    int r1 = num % billion;
    if (q1 > 0)
    {
        process(q1, result);
        result += units[0];
        result += " ";
    }
    int q2 = r1 / million;
    int r2 = r1 % million;
    if (r1 > 0)
    {
        process(q2, result);
        result += units[1];
        result += " ";
    }
    int q3, r3;
    if (r2 > 0)
    {
        process(q3, result);
        q3 = r2 / thousand;
        r3 = r2 % thousand;

        result += units[2];
        result += " ";
    }

    if (r3 > 0)
    {
        process(r3, result);
    };

    cout << result.erase((int)result.length() - 1, 1) << endl;
}

int main()
{
    numToWords(1234567);
}