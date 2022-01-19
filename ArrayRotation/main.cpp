#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/array-rotation/#
/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int count = 0;
    for (int i = 0; count < n; i++)
    {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        do
        {
            int k = (j + d) % n;

            if (k == i)
            {
                arr[j] = temp; // Eventually, the copy will cirle back to the initial element i, this is the end for the inner loop.
            }
            else
            {
                arr[j] = arr[k];
            }

            count++;
            j = k;
        } while (j != i);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

/* Driver program to test above functions */
int main()
{
    for (int i = 0; i < 10; i++)
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = sizeof(arr) / sizeof(arr[0]);

        // Function calling
        leftRotate(arr, i, n);
        printArray(arr, n);
    }

    return 0;
}