#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct IncreSequence
{
    int end;
    int size;
};

// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int LongestIncreasingSubsequenceSize(vector<int> &input)
{
    vector<int> tail(input.size());
    int length = 1;
    tail[0] = input[0];

    for (int i = 1; i < input.size(); ++i)
    {
        auto it = lower_bound(input.begin(), input.begin() + length, input[i]);
        if (it == input.begin() + length)
        {
            tail[length++] = input[i];
        }
        else
        {
            *it = input[i];
        }
    }

    return length;
}

int main(int, char **)
{
    std::vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};

    std::cout << "Length of longest subsequence size: "
              << LongestIncreasingSubsequenceSize(v) << "\n";
}
