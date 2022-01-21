#include <iostream>
#include <string>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

// Recursive from the index of 0, pass down the current count of common characters.
template <bool COMMONSUBSEQUENCE>
int LCS_Recur_FromFront(const string &s1, int index1, const string &s2, int index2, int currCount)
{
    if (s1.size() <= index1 || s2.size() <= index2)
        return currCount; // On of the strings ended, this is the result.

    if (s1[index1] == s2[index2]) // Current characters are equal.
    {
        return LCS_Recur_FromFront<COMMONSUBSEQUENCE>(s1, index1 + 1, s2, index2 + 1, currCount + 1); // Found equal characters, currCount + 1, recursive call to count the rest strings.
    }

    if constexpr (COMMONSUBSEQUENCE)
        return max(LCS_Recur_FromFront<COMMONSUBSEQUENCE>(s1, index1 + 1, s2, index2, currCount), LCS_Recur_FromFront<COMMONSUBSEQUENCE>(s1, index1, s2, index2 + 1, currCount)); // Longest Common Subsequence, currCount not changed, carry on.
    else
        return max(currCount, max(LCS_Recur_FromFront<COMMONSUBSEQUENCE>(s1, index1 + 1, s2, index2, 0), LCS_Recur_FromFront<COMMONSUBSEQUENCE>(s1, index1, s2, index2 + 1, 0))); // Longest Common Substring, count the both strings started from 0, return the max count.
}

// Recursive from the last index of the strings, return the max count.
template <bool COMMONSUBSEQUENCE>
int LCS_Recur_FromEnd(const string &s1, int index1, const string &s2, int index2)
{
    if (index1 < 0 || index2 < 0)
        return 0; // No more to count.

    if (s1[index1] == s2[index2]) // Current characters are equal.
    {
        if constexpr (COMMONSUBSEQUENCE)
        {
            return LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(s1, index1 - 1, s2, index2 - 1) + 1; // Always +1 for common subsequence, no recount.
        }
        else
        {
            if (index1 > 0 && index2 > 0 && s1[index1 - 1] == s2[index2 - 1])
            {
                return LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(s1, index1 - 1, s2, index2 - 1) + 1; // The previous character is also equal, increase the result by 1.
            }
            else
            {
                return max(1, LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(s1, index1 - 1, s2, index2 - 1)); // Recount, at least 1 equal character, or the count of substring.
            }
        }
    }

    return max(LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(s1, index1 - 1, s2, index2), LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(s1, index1, s2, index2 - 1)); // Current characters are not equal, the count depends on the rest strings.
}

template <bool COMMONSUBSEQUENCE>
int LCSubStr_DP(const string &s1, const string &s2)
{
    vector<vector<int>> dp(2, vector<int>(s2.size() + 1, 0));
    int i;
    for (i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            if (s1[i - 1] == s2[j - 1]) // Current characters are equal.
            {
                if constexpr (COMMONSUBSEQUENCE)
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1; // Always +1 for common subsequence, no recount.
                }
                else
                {
                    if (i > 1 && j > 1 && s1[i - 2] == s2[j - 2])
                        dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1; // The previous character is also equal, increase the result by 1.
                    else
                        dp[i % 2][j] = max(dp[(i - 1) % 2][j - 1], 1); // Recount, at least 1 equal character, or the count of substring.
                }
            }
            else
            {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]); // Current characters are not equal, the count depends on the rest strings.
            }
        }
    }

    return dp[--i % 2][s2.size()];
}

template <bool COMMONSUBSEQUENCE>
void test()
{
    vector<string> ss1 = {"GeeksforGeeks", "abcdxyz", "zxabcdezy", "Site:GeeksforGeeks", "AGGTAB"};
    vector<string> ss2 = {"GeeksQuiz", "xyzabcd", "yzabcdezx", "Site:GeeksQuiz", "GXTXAYB"};

    if constexpr (COMMONSUBSEQUENCE)
    {
        cout << "Length of Longest Common Subsquence of:\n";
    }
    else
    {
        cout << "Length of Longest Common Substring of:\n";
    }

    for (int i = 0; i < ss1.size(); ++i)
    {

        cout << "[" << ss1[i] << "] and [" << ss2[i] << "] is :\n"
             << "Rcv1: "
             << LCS_Recur_FromFront<COMMONSUBSEQUENCE>(ss1[i], 0, ss2[i], 0, 0)
             << "\n"
             << "Rcv2: "
             << LCS_Recur_FromEnd<COMMONSUBSEQUENCE>(ss1[i], ss1[i].size() - 1, ss2[i], ss2[i].size() - 1)
             << "\n"
             << "DP: "
             << LCSubStr_DP<COMMONSUBSEQUENCE>(ss1[i], ss2[i])
             << "\n";
    }
}

int main(int, char **)
{
    test<true>();
    cout << "\n";
    test<false>();
}
