// C++ program to find first and last occurrences of
// a number in a given sorted array
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

/* if x is present in arr[] then returns the index of
FIRST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int first(int arr[], int low, int high, int x)
{
  if(low >= high) return arr[low] == x ? low : -1;

  int mid = (high + low) / 2;

  if (arr[mid] < x)
    return first(arr, (mid + 1), high, x);
  else
    return first(arr, low, mid, x);
}

/* if x is present in arr[] then returns the index of
LAST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int last(int arr[], int low, int high, int x)
{
  if(low >= high) return low > 0 && arr[low - 1] == x ? low - 1 : -1; // low will be finally pointing to the next index of last x.
  
  int mid = (high + low) / 2;
	
  if(arr[mid] <= x)
    return last(arr, mid + 1, high, x);
  else
    return last(arr, low, mid, x);
}

void findFirstAndLast(int arr[], int n, int x)
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
	cout << "First: " << first << ", Last: " << last << "\n";
}

// Driver program
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 8;
	cout << "val: " << x << "\n";
	cout << "first: " << first(arr, 0, n, x) << ", last: " << last(arr, 0, n, x) << "\n";
	findFirstAndLast(arr, n, x);

	x = 2;
	cout << "val: " << x << "\n";
	cout << "first: " << first(arr, 0, n, x) << ", last: " << last(arr, 0, n, x) << "\n";
	findFirstAndLast(arr, n, x);

	x = 5;
	cout << "val: " << x << "\n";
	cout << "first: " << first(arr, 0, n, x) << ", last: " << last(arr, 0, n, x) << "\n";
	findFirstAndLast(arr, n, x);

	x = 9;
	cout << "val: " << x << "\n";
	cout << "first: " << first(arr, 0, n, x) << ", last: " << last(arr, 0, n, x) << "\n";
	findFirstAndLast(arr, n, x);

	x = 0;
	cout << "val: " << x << "\n";
	cout << "first: " << first(arr, 0, n, x) << ", last: " << last(arr, 0, n, x) << "\n";
	findFirstAndLast(arr, n, x);

	return 0;
}
