#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

enum
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};
using namespace std;

class Solution
{
  public:
    int findElement(vector<int> temp, int target)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == target)
                return i;
        }
        return -1;
    }

    int romanToInt(string s)
    {
        int result = 0;
        vector<int> temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
                temp.push_back(1);
            if (s[i] == 'V')
                temp.push_back(5);
            if (s[i] == 'X')
                temp.push_back(10);
            if (s[i] == 'L')
                temp.push_back(50);
            if (s[i] == 'C')
                temp.push_back(100);
            if (s[i] == 'D')
                temp.push_back(500);
            if (s[i] == 'M')
                temp.push_back(1000);
        }
        char priority[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int prior[7] = {M, D, C, L, X, V, I};
        // for (int i = 0; i < temp.size(); i++)
        // cout << temp[i] << endl;
        for (int i = 0; i < 7; i++)
        {
            int marks = 1;
            while (1)
            {
                marks = findElement(temp, prior[i]);
                // cout << marks << endl;
                if (marks != -1) // found the letter.
                {
                    int tempSum = 0;
                    tempSum += temp[marks];
                    marks--; // give the letter to the tempsum and check if the left side
                             // has any letter.

                    if (marks == -1) // first letter is the matched letter.
                    {
                        result += tempSum;
                        temp[0] = 0;
                        continue;
                    }
                    else // the rest of letter is the matched letter
                    {
                        while (marks != -1 && temp[marks] != 0)
                        {
                            tempSum -= temp[marks];
                            temp[marks + 1] = 0;
                            temp[marks] = 0;
                            marks--;
                        }
                        if (temp[marks] == 0)
                        {
                            result += tempSum;

                            temp[marks + 1] = 0;

                            continue;
                        }
                    }
                }
                else
                    break;
            }
        }

        // for (int i = 1; i < temp.size(); i++)
        // {

        //     if (temp[i] == temp[i - 1])
        //     {
        //     }
        //     if ((temp[i - 1] < temp[i]) &&
        //         (temp[i - 1] == 1 || temp[i - 1] == 10 || temp[i - 1] == 100))
        //     {
        //     }
        //     if ((temp[i] > temp[i + 1]) &&
        //         (temp[i + 1] == 1 || temp[i + 1] == 10 || temp[i + 1] == 100))
        //     {
        //     }
        // }
        return result;
    }
};
int main()
{
    string a = "IV";
    Solution temp;

    int result = temp.romanToInt(a);
    cout << result;
    return 0;
}