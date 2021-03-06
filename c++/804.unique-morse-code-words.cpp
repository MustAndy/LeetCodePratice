/*
 * @Author: AndyWong 
 * @Date: 2018-09-19 16:55:46 
 * @Last Modified by:   AndyWong 
 * @Last Modified time: 2018-09-19 16:55:46 
 */
/*
 * [822] Unique Morse Code Words
 *
 * https://leetcode.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (71.55%)
 * Total Accepted:    37.4K
 * Total Submissions: 52.2K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * International Morse Code defines a standard encoding where each letter is
 * mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b"
 * maps to "-...", "c" maps to "-.-.", and so on.
 *
 * For convenience, the full table for the 26 letters of the English alphabet
 * is given below:
 *
 *
 *
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 *
 * Now, given a list of words, each word can be written as a concatenation of
 * the Morse code of each letter. For example, "cab" can be written as
 * "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll
 * call such a concatenation, the transformation of a word.
 *
 * Return the number of different transformations among all words we have.
 *
 *
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation:
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 *
 * There are 2 different transformations, "--...-." and "--...--.".
 *
 *
 *
 *
 * Note:
 *
 *
 * The length of words will be at most 100.
 * Each words[i] will have length in range [1, 12].
 * ⁠   words[i] will only consist of lowercase letters.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

static string code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                          "....", "..", ".---", "-.-", ".-..", "--", "-.",
                          "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                          "...-", ".--", "-..-", "-.--", "--.."};
class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> result;

        for (int i = 0; i < words.size(); i++)
        {
            string temp;
            for (int j = 0; j < words[i].length(); j++)
                temp += code[words[i][j] - 97];
            int Vectorlength = result.size();
            bool isSame = false;
            for (int l = 0; l < Vectorlength; l++)
                if (temp == result[l])
                    isSame = true;
            if (isSame == false)
                result.push_back(temp);
        }

        return result.size();
    }
};
