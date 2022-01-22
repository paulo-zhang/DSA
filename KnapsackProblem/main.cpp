#include <iostream>
#include <vector>

using namespace std;
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int knapSack_recursive(int w, int wt[], int val[], int n)
{
    if (w == 0 || n == 0)
        return 0; // No more capacity nor item.

    if (w < wt[n - 1])
        return knapSack_recursive(w, wt, val, n - 1); // Too big, don't include current item.

    return max(knapSack_recursive(w, wt, val, n - 1),                           // Case1: do not include current item.
               val[n - 1] + knapSack_recursive(w - wt[n - 1], wt, val, n - 1)); // Case2: include current item.
}

int knapSack_dp(int w, int wt[], int val[], int n)
{
    vector<vector<int>> k_dp(2, vector<int>(w + 1, 0)); // All the best choices.
    int i;
    for (i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (wt[i - 1] > j)
            {
                k_dp[i % 2][j] = k_dp[(i - 1) % 2][j]; // Too big, don't include current item.
                continue;
            }

            k_dp[i % 2][j] = max(k_dp[(i - 1) % 2][j],                           // Case1: do not include current item.
                                 val[i - 1] + k_dp[(i - 1) % 2][j - wt[i - 1]]); // Case2: include current item (the weight contributed by current item: wt[n - 1]).
        }
    }

    return k_dp[(i - 1) % 2][w];
}

int knapSack_dp2(int w, int wt[], int val[], int n)
{
    vector<int> k_dp(w + 1, 0); // All the best choices.

    for (int i = 1; i <= n; ++i)
    {
        for (int j = w; j >= wt[i - 1]; --j) // Loop from the back.
        {
            k_dp[j] = max(k_dp[j],                           // Case1: do not include current item.
                          val[i - 1] + k_dp[j - wt[i - 1]]); // Case2: include current item (the weight contributed by current item: wt[n - 1]).
        }
    }

    return k_dp[w];
}

int main(int, char **)
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "knapSack_recursive: " << knapSack_recursive(W, wt, val, n) << "\n";
    cout << "knapSack_dp: " << knapSack_dp(W, wt, val, n) << "\n";
    cout << "knapSack_dp2: " << knapSack_dp2(W, wt, val, n) << "\n";
}
