#include <iostream>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/coin-change-dp-7/
// https://www.educative.io/edpresso/coin-change-problem-2-finding-the-number-of-ways-to-make-a-sum

int countCoinChange(const vector<int> &coins, int sum)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1; // sum = 0, 1 solution.

    for (size_t i = 0; i < coins.size(); ++i)
    {
        for (size_t j = coins[i]; j <= sum; ++j)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main(int, char **)
{
    vector<int> coins = {1, 2, 5};
    std::cout << "count: " << countCoinChange(coins, 7) << "\n";
}
