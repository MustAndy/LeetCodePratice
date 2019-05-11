/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (43.78%)
 * Total Accepted:    203.1K
 * Total Submissions: 463.8K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */
// #include <iostream>
// #include <map>

// using namespace std;
// class Solution
// {
//   public:
//     bool isHappy(int n)
//     {
//         map<int, int> resultMap;
//         map<int, int>::iterator iter;
//         while (1)
//         {
//             if (n == 1)
//                 break;

//             if ((iter = resultMap.find(n)) != resultMap.end())
//                 break;
//             else
//                 resultMap.insert(pair<int, int>(n, 1));

//             n = tempSum(n);
//         }
//         return (n == 1);
//     }

//   private:
//     int tempSum(int n)
//     {
//         int result = 0;
//         int dd;
//         while (n > 0)
//         {
//             dd = n % 10;
//             n /= 10;
//             result += dd * dd;
//         }
//         return result;
//     }
// };

#include <unordered_set>
using namespace std;

class Solution
{
  public:
    bool isHappy(int n)
    {
        unordered_set<int> us;
        unordered_set<int>::iterator it;

        while (true)
        {
            if (n == 1)
            {
                break;
            }
            if (us.find(n) == us.end())
            {
                us.insert(n);
            }
            else
            {
                break;
            }
            n = dsum(n);
        }
        return n == 1;
    }

  private:
    int dsum(int n)
    {
        int s = 0;
        int d;
        while (n > 0)
        {
            d = n % 10;
            n /= 10;
            s += d * d;
        }

        return s;
    }
};