#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/

template <bool HAS_DUPLICATION>
void printPickPermutations(const string &s, string &l)
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

            c = s[i];
        }

        string temp = s.substr(0, i) + s.substr(i + 1);
        l += s[i];
        printPickPermutations<HAS_DUPLICATION>(temp, l); // pick one elment and add it to the result string.
        l.pop_back();
    }
}

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
template <bool HAS_DUPLICATION> // Duplication = true not working.
void PrintSwapPermutations(string &a, int l, int r)
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
            c = a[i];
        }

        // Swapping done
        swap(a[l], a[i]); // swap one with any other elements.

        // Recursion called
        PrintSwapPermutations<HAS_DUPLICATION>(a, l + 1, r);

        // backtrack
        swap(a[l], a[i]);
    }
}

bool nextPermutation(string &s) { // Always try to find a 'bigger' array.
    int k = -1;
    for(int i = s.size() - 2; i >= 0; i --){ // Find the first number from the back that is smaller.
        if(s[i] < s[i + 1]){
            k = i;
            break;
        }
    }
    
    if(k == -1){
        return false; // descending order, the permutating ends.
    }
    else{
        for(int i = s.size() - 1; i > k; i --){
            if(s[i] > s[k]){
                swap(s[i], s[k]);// Swap to make a 'bigger' array.
                reverse(s.begin() + k + 1, s.end()); // Sort the array at the back, since it's in descending order, reverse is faster.
                break;
            }
        }
    }
    
    return true;
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
    cout <<"\nswap: \n";
    PrintSwapPermutations<HAS_DUPLICATION>(input, 0, n - 1); // This does not work when HAS_DUPLICATION == true.
    cout <<"\npick: \n";
    string l;
    printPickPermutations<HAS_DUPLICATION>(input, l);
    cout <<"\nnext: \n";
    cout << input << ", ";
    sort(input.begin(), input.end()); // Need to sort for it to work.
    while(nextPermutation(input)){
        cout << input << ", ";
    }
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
    test<true>("01009");
    return 0;
}