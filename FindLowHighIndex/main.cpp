// C++ program to find first and last occurrences of
// a number in a given sorted array
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

/* if x is present in arr[] then returns the index of
FIRST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int lower(int arr[], int low, int high, int x)
{
  if(low > high) return low;

  int mid = (high + low) / 2;

  if (arr[mid] < x)
    return lower(arr, mid + 1, high, x);
  else
    return lower(arr, low, mid - 1, x);
}

/* if x is present in arr[] then returns the index of
LAST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int upper(int arr[], int low, int high, int x)
{
  if(low > high) return low; // low will be finally pointing to the next index of last x.
  
  int mid = (high + low) / 2;
	
  if(arr[mid] <= x)
    return upper(arr, mid + 1, high, x);
  else
    return upper(arr, low, mid - 1, x);
}

void findFirstAndLast(int arr[], int n, int x)
{
	int first, last;
	// to store first occurrence
	first = lower(arr, 0, n - 1, x);
	// to store last occurrence
	last = upper(arr, 0, n - 1, x) - 1;

	if (first > last) {
		first = -1;
		last = -1;
	}

	cout << "First: " << first << ", Last: " << last << "\n";
}

void std_LowUpper(int arr[], int n, int x)
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
	findFirstAndLast(arr, n, x);
	std_LowUpper(arr, n, x);

	x = 2;
	cout << "val: " << x << "\n";
	findFirstAndLast(arr, n, x);
	std_LowUpper(arr, n, x);

	x = 5;
	cout << "val: " << x << "\n";
	findFirstAndLast(arr, n, x);
	std_LowUpper(arr, n, x);

	x = 9;
	cout << "val: " << x << "\n";
	findFirstAndLast(arr, n, x);
	std_LowUpper(arr, n, x);

	x = 0;
	cout << "val: " << x << "\n";
	findFirstAndLast(arr, n, x);
	std_LowUpper(arr, n, x);

	return 0;
}
