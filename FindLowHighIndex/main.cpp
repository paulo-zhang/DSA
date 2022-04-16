// C++ program to find first and last occurrences of
// a number in a given sorted array
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

/* if x is present in arr[] then returns the index of
FIRST occurrence of x in arr[0..n-1], otherwise
returns -1 */
pair<int, int> searchRange(int arr[], int n, int x) {
        if(n == 0) return pair<int, int>{-1, -1}; // 1. Check empty.
        
        int low = 0, high = n - 1;
        while(low <= high){ // 2. Use '<='.
            int mid = (low + high) / 2;
            
            if(arr[mid] >= x){ // 3. Use '>=', only move low when low is not pointing to the answer to make sure low will point to lower bound.
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        if(low >= n || arr[low] != x){ // 4. low could overflow if target is not found.
            return pair<int, int>{-1, -1};
        }
        
        int first = low; // 5. Save the first result.
        high = n - 1; // 6. Set the new search boundary, low is not changed.
        while(low <= high){ // Also use '<='.
            int mid = (low + high) / 2;
            
            if(arr[mid] > x){ // Use '>' (the only difference with previous while loop), only move high when high is not pointing to the answer to make sure high will point to the last target value.
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return pair<int, int>{first, high};
    }

pair<int, int> std_LowUpper(int arr[], int n, int x)
{
	int first, last;
	// to store first occurrence
	first = lower_bound(arr, arr + n, x) - arr;
	// to store last occurrence
	last = upper_bound(arr, arr + n, x) - arr - 1;

	if (first > last) { 
		first = -1;
		last = -1;
	}

	return pair<int, int>{first, last};
}

ostream& operator <<(ostream& os, const pair<int, int>& p){
	return os << "first: " << p.first << ", second: " << p.second << "\n";
}

// Driver program
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 8;
	cout << "val: " << x << "\n";
	cout << searchRange(arr, n, x);
	cout << std_LowUpper(arr, n, x);

	x = 2;
	cout << "val: " << x << "\n";
	cout << searchRange(arr, n, x);
	cout << std_LowUpper(arr, n, x);

	x = 5;
	cout << "val: " << x << "\n";
	cout << searchRange(arr, n, x);
	cout << std_LowUpper(arr, n, x);

	x = 9;
	cout << "val: " << x << "\n";
	cout << searchRange(arr, n, x);
	cout << std_LowUpper(arr, n, x);

	x = 0;
	cout << "val: " << x << "\n";
	cout << searchRange(arr, n, x);
	cout << std_LowUpper(arr, n, x);

	return 0;
}
