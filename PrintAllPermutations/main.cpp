#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/

template <bool HAS_DUPLICATION>
void printPickPermutations(string s, string l)
{
    if (s.empty()) // no more to pick.
    {
        cout << l << ", ";
        return;
    }

    char c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if constexpr (HAS_DUPLICATION) // The code used to remove duplicate permutations.
        {
            if (c == s[i])
            {
                continue;
            }
            else
            {
                c = s[i];
            }
        }

        string temp = s.substr(0, i) + s.substr(i + 1);
        printPickPermutations<HAS_DUPLICATION>(temp, l + s[i]); // pick one elment and add it to the result string.
    }
}

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
template <bool HAS_DUPLICATION>
void PrintSwapPermutations(string a, int l, int r)
{
    // Base case
    if (l == r) // no more to swap.
    {
        cout << a << ", ";
        return;
    }

    char c = 0;
    // Permutations made
    for (int i = l; i <= r; i++)
    {
        if constexpr (HAS_DUPLICATION) // The code used to remove duplicate permutations.
        {
            if (c == a[i])
            {
                continue;
            }
            else
            {
                c = a[i];
            }
        }

        // Swapping done
        swap(a[l], a[i]); // swap one with any other elements.

        // Recursion called
        PrintSwapPermutations<HAS_DUPLICATION>(a, l + 1, r);

        // backtrack
        swap(a[l], a[i]);
    }
}

template <bool HAS_DUPLICATION>
void test(string input)
{
    if constexpr (HAS_DUPLICATION)
    {
        sort(input.begin(), input.end()); // Need to sort for it to work.
    }

    int n = input.size();
    cout << input << ": \n";
    PrintSwapPermutations<HAS_DUPLICATION>(input, 0, n - 1);
    cout << "\n";
    printPickPermutations<HAS_DUPLICATION>(input, "");
    cout << "\n\n";
}

#include <optional>
// Driver Code
int main()
{
    optional<string> opt = {};
    cout << opt.value_or("");

    test<false>("ABCD");
    test<true>("ABCC");
    return 0;
}