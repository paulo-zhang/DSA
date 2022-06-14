/*
You are an amazon delivery and you have some boxes that you have to deliver, but there are some conditions -

You can take 2 boxes of same weight in one round
you can take 3 boxes of same weight in one round
You have to find the minimum number of rounds to deliver the boxes or -1 if it is not possible to deliver them.

Example cases -
Input: boxes - [2, 2, 3, 3, 2, 4, 4, 4, 4, 4]
Output: 4
Explanation: 3 boxes of weight 2 in 1st round, 2 boxes of weight 3 in 2nd round, 3 boxes of wt 4 in 3rd and 2 boxes of wt 4 in 4th round.

Input: boxes - [2, 3, 3]
Output: -1
Explanation: There is only one box with weight 2 and we can only take either 2 or 3 boxes in one round not lesser.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

int dp[1000000] = {0}; // 0: not calcuated, -1: impossible, other: deliver rounds.
// return the minmum rounds, or -1 if it's impossible.
int minimumRounds(int count)
{
    // base cases.
    if (count == 0)
        return 0;
    else if (count < 0)
        return -1;

    // memorization.
    if (dp[count] == -1)
        return -1;
    else if (dp[count] > 0)
        return dp[count];

    int r = minimumRounds(count - 3); // try deliver 3.
    if (r < 0)
    {
        r = minimumRounds(count - 2); // try deliver 2
    }

    if (r >= 0)
    {
        dp[count] = r + 1;
    }
    else
    {
        dp[count] = -1;
    }

    return dp[count];
}

int minimumRounds(vector<int> weights)
{
    unordered_map<int, int> counts;
    for (int w : weights)
    {
        counts[w]++;
    }

    int rounds = 0;
    for (auto p : counts)
    {
        int r = minimumRounds(p.second);
        if (r == -1)
            return -1;
        rounds += r;
    }

    return rounds;
}

int main(int, char **)
{
    assert(minimumRounds({2, 2, 3, 3, 2, 4, 4, 4, 4, 4}) == 4);
    assert(minimumRounds({2, 3, 3}) == -1);
    assert(minimumRounds({3, 3, 3}) == 1);
    assert(minimumRounds({3, 3, 3, 3}) == 2);
    assert(minimumRounds({3, 3, 3, 3, 3, 3, 3}) == 3);
    assert(minimumRounds({3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}) == 4);
}
