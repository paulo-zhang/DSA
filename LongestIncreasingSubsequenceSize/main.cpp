#include <iostream>
#include <vector>
#include <set>

using namespace std;

// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int LongestIncreasingSubsequenceSize(vector<int> &input)
{
    vector<int> tail(input.size());
    int length = 1;
    tail[0] = input[0];

    for (int i = 1; i < input.size(); ++i)
    {
        auto it = lower_bound(tail.begin(), tail.begin() + length, input[i]); // Binary search
        if (it == tail.begin() + length) { // input[i] is bigger than any of the previous numbers.
            tail[length++] = input[i]; // Extend the length, and only mark down the end number of the sequence.
        }
        else { // input[i] is not the biggest, *it >= input
            *it = input[i]; // Replace *it, so that we maintain 'end element of smaller list is smaller than end elements of larger lists', and potentially forming the longer sequence.
        }
    }

    return length;
}

void printVector(const vector<int> &v, int len)
{
    cout << "Length of longest subsequence (";
    for(int i = 0;i < v.size();i ++){
        if(i != 0){
            cout << ", ";
        }

        cout << v[i];
    }

    cout << "): " << len << "\n";
}

int main(int, char **)
{
    vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
    int len = LongestIncreasingSubsequenceSize(v);
    printVector(v, len);

    vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    len = LongestIncreasingSubsequenceSize(v2);
    printVector(v2, len);

    vector<int> v3{9, 8, 7, 6, 5, 4, 3, 2, 1};
    len = LongestIncreasingSubsequenceSize(v3);
    printVector(v3, len);
}
