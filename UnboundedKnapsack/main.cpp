#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

int unboundedKnapsack(int totalWeight, vector<int> values, vector<int> weights)
{
    vector<int> dp(totalWeight + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= totalWeight; ++i)
    {
        for (int j = 0; j < values.size(); ++j)
        {
            if (weights[j] > i)
                continue;

            dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
        }
    }

    return dp[totalWeight];
}

int unboundedKnapsack_Recursive(int totalWeight, vector<int> values, vector<int> weights)
{
    int maxValue = 0;
    for (int i = 0; i < values.size(); ++i)
    {
        if (totalWeight < weights[i])
            continue;

        maxValue = max(maxValue, values[i] + unboundedKnapsack_Recursive(totalWeight - weights[i], values, weights));
    }

    return maxValue;
}

int main(int, char **)
{
    int totalWeight = 100;
    vector<int> values = {10, 30, 20};
    vector<int> weights = {5, 10, 15};

    cout << "unboundedKnapsack: " << unboundedKnapsack(totalWeight, values, weights) << "\n";
    cout << "unboundedKnapsack_Recursive: " << unboundedKnapsack_Recursive(totalWeight, values, weights) << "\n";
    return 0;
}
