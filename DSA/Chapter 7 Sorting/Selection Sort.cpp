// Implementation of selection sort
#include <bits/stdc++.h>

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << " " << arr[i];

    std::cout << std::endl;
}

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        std::cout << "\nPass " << i + 1 << std::endl;

        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
            std::swap(arr[min_idx], arr[i]);
            printArray(arr, n);
    }
}

// Driver program
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array:" << std::endl;
    printArray(arr, n);

    // Function Call
    selectionSort(arr, n);

    std::cout << "\nSorted array:" << std::endl;
    printArray(arr, n);

    return 0;
}


