#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;

/*
max number of subarrays where left and right index positions difference is less or equal than k
k = 3 array=[1, 3 , 5]
explanation: for index (0,0) the difference is diff = {abs(1 - 1)}, diff < k so that is the first subarray.
for index (0,1) the difference is diff = {abs(1 - 3)}, diff < k so that is the second subarray.
for index (1,1) the difference is diff = {abs(3 - 3)}, diff < k so that is the third subarray.
for index (1,2) the difference is diff = {abs(3 - 5)}, diff < k so that is the fourth subarray.
for index (2,2) the difference is diff = {abs(5 - 5)}, diff < k so that is the fifth subarray.
But for index (0,2) the difference is diff = {abs(1 - 5)}, diff > k so that is NOT a subarray.
The total amount of subarray is 5
*/

int totalSubArrays(vector<int> arr, int k){
	sort(arr.begin(), arr.end());
	
	int count = arr.size(); // the answer, at least n.
	int start = 0; // the start of the sub-array that the difference of any two elements is less or equal to k.
	for(int i = 1; i < arr.size();i ++){
		int diff = arr[i] - arr[start];
		while(diff > k){
			start ++;
			diff = arr[i] - arr[start];
		}
		
		count += i - start; // The idea is: arr[i] forms i - start NEW pairs that has difference no greater than k;
	}
	
	return count;
}

int main(int, char**) {
    assert(totalSubArrays({1, 3 , 5}, 3) == 5);
}
