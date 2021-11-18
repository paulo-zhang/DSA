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

        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
            {
                arr[j] = temp;
                count++;
                break;
            }

            arr[j] = arr[k];
            count++;
            j = k;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}