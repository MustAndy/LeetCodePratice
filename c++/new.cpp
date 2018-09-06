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

int main()
{
    Solution temp;
    vector<string> words;
    words.push_back("gin");
    words.push_back("zen");
    words.push_back("gig");
    words.push_back("msg");

    int result = temp.uniqueMorseRepresentations(words);
    cout << result;
    return 0;
}