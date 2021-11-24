#include <iostream>
#include <string>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

int findLongestPalindrome(string input, int begin, int end)
{
    if (begin > end)
        return 0;

    if (begin == end)
        return 1; // The middle

    if (input[begin] == input[end])
        return 2 + findLongestPalindrome(input, begin + 1, end - 1);

    return max(findLongestPalindrome(input, begin + 1, end), findLongestPalindrome(input, begin, end - 1));
}

int findLongestPalindrome_dp(string input)
{
    vector<vector<int>> dp(input.size(), vector<int>(input.size(), 0));
    int maxPalindrome = 0;

    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (input[i] == input[j])
                dp[i][j] = 2 + dp[i - 1][j + 1];
            else
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);

            maxPalindrome = max(maxPalindrome, dp[i][j]);
        }
    }

    return maxPalindrome;
}

string getLongestPalindrome_dp(string input)
{
    vector<vector<int>> dp(input.size(), vector<int>(input.size(), 0));
    int maxPalindrome = 0, x, y;

    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (input[i] == input[j])
                dp[i][j] = 2 + dp[i - 1][j + 1];
            else
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);

            if (maxPalindrome < dp[i][j])
            {
                maxPalindrome = max(maxPalindrome, dp[i][j]);
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << "\n";
    }

    string s1, s2;
    while (x > y)
    {
        if (dp[x][y] == 1)
        {
            s1 += input[x];
            break;
        }

        s1 += input[y];
        s2 = input[x] + s2;
    }

    return s1 + s2;
}

int main(int, char **)
{
    string str = "ABBDCACB";

    cout << "The length of the longest palindromic subsequence is: \nRecursive:"
         << findLongestPalindrome(str, 0, str.size() - 1) << "\n"
         << "dp:" << findLongestPalindrome_dp(str) << "\n";

    // cout << "getLongestPalindrome_dp: " << getLongestPalindrome_dp(str) + "\n";

    return 0;
}
