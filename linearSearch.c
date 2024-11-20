#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>
#include <stdio.h>

// Function to search for an element 'x' in an array 'arr' of size 'N'
int search(int arr[], int N, int x) {
    // Iterate through the array from the beginning
    for (int i = 0; i < N; i++) {
        // Check if the current element is equal to the target 'x'
        if (arr[i] == x) {
            // If found, return the index of the element
            return i;
        }
    }
    // If the element is not found after iterating through the entire array, return -1
    return -1;
}

// Our main function
int main(void) {
    // We declare and initialize an integer array 'arr'
    int arr[] = { 2, 3, 4, 10, 40 };
    // We declare and initialize the target element to search for
    int x = 40;
    // We calculate the size of the array 'arr'
    int N = sizeof(arr) / sizeof(arr[0]);

    // Call the 'search' function to find the index of 'x' in 'arr'
    int result = search(arr, N, x);

    // If 'result' is -1, print "Element is not present in array"
    // Otherwise, print "Element is present at index %d", where %d is replaced by 'result'
    (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);

    return 0;
}