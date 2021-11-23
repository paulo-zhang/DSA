#include <iostream>
#include <vector>
#include <algorithm>

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
            dp[j] = dp[j] + // Solutions that do not contain current coin (or Sm). 
                dp[j - coins[i]]; // Solutions that contain at least one Sm (the one the the last Sm units.). 
        }
    }

    return dp[sum];
}

int countCoinChange_recursive(const vector<int> &coins, int sum, int index = 0)
{
    if (sum < 0 || index >= coins.size())
        return 0;

    if (sum == 0)
    {
        return 1;
    }

    int count = countCoinChange_recursive(coins, sum - coins[index], index); // Solutions that contain at least one Sm (the one the the last Sm units.).
    count += countCoinChange_recursive(coins, sum, index + 1);               // Solutions that do not contain current coin (or Sm).

    return count;
}

int main(int, char **)
{
    vector<int> coins = {2, 5};
    std::cout << "coins: ";
    for_each(coins.begin(), coins.end(), [](auto c){cout << c << ", ";});
    cout << "\n";

    int sum = 0;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 3;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 4;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 5;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 7;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 8;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 10;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 13;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 15;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 20;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 120;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
    sum = 390;
    std::cout << "countCoinChange(" << sum << "): " << countCoinChange(coins, sum) << ", recursive(" << sum << "): " << countCoinChange_recursive(coins, sum) << "\n";
}
