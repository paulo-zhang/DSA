#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/

template <bool HAS_DUPLICATION>
void printAllPermutations(string s, string l)
{
    if (s.length() < 1)
    {
        cout << l + s << ", ";
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

        string temp = "";
        if (i < s.length() - 1)
        {
            temp = s.substr(0, i) + s.substr(i + 1);
        }
        else
        {
            temp = s.substr(0, i);
        }
        printAllPermutations<HAS_DUPLICATION>(temp, l + s[i]);
    }
}

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
template <bool HAS_DUPLICATION>
void PrintPermutations(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << ", ";
    else
    {
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
            swap(a[l], a[i]);

            // Recursion called
            PrintPermutations<HAS_DUPLICATION>(a, l + 1, r);

            // backtrack
            swap(a[l], a[i]);
        }
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
    PrintPermutations<HAS_DUPLICATION>(input, 0, n - 1);
    cout << "\n";
    printAllPermutations<HAS_DUPLICATION>(input, "");
    cout << "\n\n";
}

// Driver Code
int main()
{
    test<false>("ABCD");
    test<true>("ABCC");
    return 0;
}