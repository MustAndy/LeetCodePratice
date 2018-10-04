/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:56:08
 * @Last Modified by:   AndyWong
 * @Last Modified time: 2018-09-19 16:56:08
 */
/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.54%)
 * Total Accepted:    392.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int findEnd(string s) {
    int marks;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        marks = i;
        return marks;
      }
    }
    return -1;
  }
  int findBegin(string s, char target, int marks) {
    if (marks == 0)
      return -1;
    (target == ')') ? target = '(' : target = target;
    (target == ']') ? target = '[' : target = target;
    (target == '}') ? target = '{' : target = target;
    for (int i = marks - 1; i >= 0; i--) {
      if (s[i] == target) {
        marks = i;
        return marks;
      } else if (s[i] == 0)
        continue;
      else {
        return -1;
      }
    }
    return -1;
  }

  bool isValid(string s) {
    int BeginMarks, EndMarks;
    if (s.length() == 0)
      return true;
    if ((EndMarks = findEnd(s)) == -1)
      return false;
    if (s.length() % 2 != 0)
      return false;
    while (1) {
      EndMarks = findEnd(s);
      if (EndMarks == -1)
        return false;

      BeginMarks = findBegin(s, s[EndMarks], EndMarks);
      if (BeginMarks == -1)
        return false;
      else if (BeginMarks == 0)
        return true;
      else {
        s[EndMarks] = 0;
        s[BeginMarks] = 0;
      }
    }
  }
};

class Solution1 {
public:
  bool isValid(string s) {
    stack<char> stack;

    for (char c : s) {
      if (c == '(') {
        stack.push(')');
      } else if (c == '[') {
        stack.push(']');
      } else if (c == '{') {
        stack.push('}');
      } else {
        if (stack.empty()) {
          return false;
        }
        char curr = stack.top();
        stack.pop();
        if (c != curr)
          return false;
      }
    }

    return stack.empty();
  }
};