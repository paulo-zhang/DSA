#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
    if (out.empty())
    {
        cout << "No subarray exist.\n";
    }
    for (auto it = out.begin(); it != out.end(); it++)
        cout << it->first << "-" << it->second << "; ";

    cout << "\n";
}

vector<pair<int, int>> findSubArrays(const vector<int> &arr)
{
    // create an empty map
    unordered_map<int, vector<int>> map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector<pair<int, int>> out;

    // Maintains sum of elements so far
    int sum = 0;
    map[0].push_back(-1); // sum of 0 before i = 0.

    for (int i = 0; i < arr.size(); i++)
    {
        // add current element to sum
        sum += arr[i];

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}

// Driver code
int main()
{
    vector<int> arr = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7, 2, -2};
    vector<pair<int, int>> out = findSubArrays(arr);

    print(out);

    return 0;
}