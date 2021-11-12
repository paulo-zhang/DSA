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

Algorithm:
If input vector is empty return result vector
 
block_size = (n-1)! ['n' is the size of vector]

Figure out which block k will lie in and select the first element of that block
(this can be done by doing (k-1)/block_size)
 
Append selected element to result vector and remove it from original input vector
 
Deduce from k the blocks that are skipped i.e k = k - selected*block_size and goto step 1
*/
using namespace std;
vector<int> facts(1, 1);
int factorial(int n){
    if(n < facts.size()) return facts[n];

    int i = facts.size();

    while(i <= n){
        facts.push_back(facts.back() * i);
        i ++;
    }

    return facts.back();
}

string FindKthPermutation(string input, int k){
	string result;
	while(!input.empty()){
        int block_size = factorial(input.size() - 1);
		int n = (k - 1) / block_size;
		result += input[n];
		input.erase(input.begin() + n);
		k -= n * block_size;
	}
	
	return result;
}

int main(){
    for(int k = 1; k <= 6; ++k){
        cout << "k: " << k << ", result: " << FindKthPermutation("123", k) << "\n";
    }
    
    return 1;
}