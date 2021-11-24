#include <iostream>
#include <string>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// https://www.geeksforgeeks.org/print-longest-palindromic-subsequence/

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

int getLongestPalindrome_Recursive(string input, int begin, int end, string &s1, string &s2)
{
    if (begin > end)
        return 0;

    if (begin == end)
    {
        s1 += input[begin];
        return 1; // The middle
    }

    if (input[begin] == input[end])
    {
        s1 += input[begin];
        s2 = input[end] + s2;
        return 2 + getLongestPalindrome_Recursive(input, begin + 1, end - 1, s1, s2);
    }

    string sn1, sn2;
    int n = getLongestPalindrome_Recursive(input, begin + 1, end, sn1, sn2);
    string sm1, sm2;
    int m = getLongestPalindrome_Recursive(input, begin, end - 1, sm1, sm2);
    if(n > m){
        s1 += sn1;
        s2 = sn2 + s2;
        return n;
    }
    else
    {
        s1 += sm1;
        s2 = sm2 + s2;
        return m;
    }
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
        }
    }

    string s1, s2;
    int x = 0;
    int y = input.size() - 1;
    while (x <= y)
    {
        if (dp[y][x] == 1)
        {
            s1 += input[x];
            break;
        }

        if(input[y] == input[x])
        {
            s1+= input[x++];
            s2 = input[y--] + s2;
        }
        else if(dp[y][x + 1] > dp[y - 1][x])
        {
            x ++;
        }
        else 
        {
            y --;
        }
    }

    return s1 + s2;
}

int main(int, char **)
{
    string str[] = {"ABBDCACB", "GEEKSFORGEEKS", "GEEKS FOR GEEKS"};

    for(const auto&s : str)
    {
        cout << "The length of the LPS of " << s << " is: \nRecursive:"
            << findLongestPalindrome(s, 0, s.size() - 1) << "\n"
            << "dp:" << findLongestPalindrome_dp(s) << "\n";

        cout << "getLongestPalindrome_dp: " << getLongestPalindrome_dp(s) + "\n";
        string s1, s2;
        getLongestPalindrome_Recursive(s, 0, s.size() - 1, s1, s2);
        cout << "getLongestPalindrome_Recursive: " <<  s1 + s2 << "\n\n";
    }
    
    return 0;
}
