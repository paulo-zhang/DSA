#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/*
Minimum number of swaps required to make a binary string palindrome. Example of a binary string - "010101".
*/

int minimumSwaps(const string &s){
    int differences = 0;
    int left = 0, right = s.size() - 1;
    while(left < right){
        if(s[left] != s[right]){
            differences ++;
        }

        left ++;
        right --;
    }

    if(differences % 2 == 0 || s.size() % 2 ==  1){ // Swap to make a palindrome: there are even number of differences or the string size is odd(swap with middle)
        return differences / 2 + differences % 2;
    }

    return -1; // Impossible to make a palindrome.
}

int main(int, char**) {
    assert(minimumSwaps("010101") == -1);
    assert(minimumSwaps("111000") == -1);
    assert(minimumSwaps("0101010") == 0);
    assert(minimumSwaps("010010") == 0);
    assert(minimumSwaps("0100110") == 1);
    assert(minimumSwaps("010111") == 1);
    assert(minimumSwaps("11110000") == 2);
}
