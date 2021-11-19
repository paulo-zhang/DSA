#include <string>
#include <iostream>
#include <vector>
/*
Given a set of ‘n’ elements, find their Kth permutation. Consider the following set of elements:
123

All permutations of the above elements are (with ordering):
1th: 123
2nd: 132
3rd: 213
4th: 231
5th: 312
6th: 321

https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/
Sanity:
The first position of an n length sequence is occupied by each of the numbers from 1 to n exactly n! / n that is (n-1)! number of times and in ascending order. So the first position of the kth sequence will be occupied by the number present at index = k / (n-1)! (according to 1-based indexing).
The currently found number can not occur again so it is removed from the original n numbers and now the problem reduces to finding the ( k % (n-1)! )th permutation sequence of the remaining n-1 numbers.
This process can be repeated until we have only one number left which will be placed in the first position of the last 1-length sequence.
The factorial values involved here can be very large as compared to k. So, the trick used to avoid the full computation of such large factorials is that as soon as the product n * (n-1) * … becomes greater than k, we no longer need to find the actual factorial value because: 
k / n_actual_factorial_value = 0 
and k / n_partial_factorial_value = 0 
when partial_factorial_value > k 
 
*/
using namespace std;
vector<uint> facts(1, 1);
uint factorial(uint n, uint k)
{
    if(n < facts.size()) return facts[n];

    uint i = facts.size();

    while(i <= n){
        facts.push_back(facts.back() * i);
        if (facts.back() >= k)
        {
            return k + 1; // Don't care the final result, n = (k - 1) / block_size will be 0, the first number will be picked.
        }
        i ++;
    }

    return facts.back();
}

string FindKthPermutation(string input, uint k)
{
    string result;
    k--;
    while (!input.empty())
    {
        uint block_size = factorial(input.size() - 1, k); // Block size of n permutations which start with 1 - n.
        uint n = k / block_size;                          // Direct access to the last block that contains Kth permutation.
        result += input[n];                               // Save the number.
        input.erase(input.begin() + n);                   // Remove the result number from next calculation.
        k = k % block_size;                               // The rest permutation numbers, next k.
    }

    return result;
}

string FindKthPermutation2(string input, uint k)
{
    string result;
    while (!input.empty())
    {
        uint block_size = factorial(input.size() - 1, k); // Block size of n permutations which start with 1 - n.
        uint n = (k - 1) / block_size;                    // Direct access to the last block that contains Kth permutation.
        result += input[n];                               // Save the number.
        input.erase(input.begin() + n);                   // Remove the result number from next calculation.
        k -= n * block_size;                              // The rest permutation numbers, next k.
    }

    return result;
}

int main(){
    string s = "123456789";
    for (uint k = 1; k <= 362880; ++k)
    {
        auto result = FindKthPermutation(s, k);
        auto result2 = FindKthPermutation2(s, k);
        if (result != result2)
            cout << "k: " << k << ", result1: " << result << ", result2: " << result2 << "\n";
    }

    /*
    1th: 123
    2nd: 132
    3rd: 213
    4th: 231
    5th: 312
    6th: 321
    */

    return 1;
}
