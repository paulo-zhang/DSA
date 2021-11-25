#include <iostream>
#include <string>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

int LCSubStr_Recursive(const string &s1, int index1, const string &s2, int index2, int count)
{
    if (s1.size() <= index1 || s2.size() <= index2)
        return count;

    if (s1[index1] == s2[index2])
    {
        return LCSubStr_Recursive(s1, index1 + 1, s2, index2 + 1, count + 1);
    }

    return max(count, max(LCSubStr_Recursive(s1, index1 + 1, s2, index2, 0), LCSubStr_Recursive(s1, index1, s2, index2 + 1, 0)));
}

int LCSubStr_DP(const string &s1, const string &s2)
{
    vector<vector<int>> dp(2, vector<int>(s2.size() + 1, 0));
    int i;
    for (i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                if (i > 1 && j > 1 && s1[i - 2] == s2[j - 2])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1; // Consecutive
                else
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j - 1], 1);
            }
            else
            {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }

    return dp[i % 2][s2.size()];
}

int main(int, char **)
{
    vector<string> ss1 = {"GeeksforGeeks", "abcdxyz", "zxabcdezy", "Site:GeeksforGeeks"};
    vector<string> ss2 = {"GeeksQuiz", "xyzabcd", "yzabcdezx", "Site:GeeksQuiz"};

    for (int i = 0; i < ss1.size(); ++i)
    {
        cout << "Length of Longest Common Substring of [" << ss1[i] << "] and [" << ss2[i] << "] is:\n"
             << "Recursive: " << LCSubStr_Recursive(ss1[i], 0, ss2[i], 0, 0) << "\n"
             << "DP: " << LCSubStr_DP(ss1[i], ss2[i]) << "\n";
    }
}
