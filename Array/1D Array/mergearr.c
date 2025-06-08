/*
============================================================================
Name        : Merge Two Arrays in C
Description : This C program demonstrates how to merge two statically declared
              arrays into a third array. It helps illustrate the concept of
              combining fixed-size arrays without using dynamic memory allocation.

Intuition:
----------------------------------------------------------------------------
C does not support built-in dynamic or resizable arrays like Python lists or 
C++ vectors. But we can simulate basic array operations using:
- Static arrays with known sizes.
- A third array to hold merged values.
- Index manipulation to copy values from one array to another.

Functional Overview:
----------------------------------------------------------------------------
1. **show()**
   - A helper function to print elements of an array from index 0 to s-1.

2. **main()**
   - Declares two input arrays (`arr1` and `arr2`) and calculates their sizes.
   - Declares a third array `arr3` large enough to store all elements.
   - Copies elements of arr1 to arr3.
   - Then copies elements of arr2 to the remaining part of arr3.
   - Prints all three arrays: original two and the merged result.

Edge Cases:
----------------------------------------------------------------------------
- Assumes both arrays are of fixed size and within bounds.
- Does not handle runtime input or dynamic sizing.
- No duplicate removal or sorting after merging.

Time Complexity:
----------------------------------------------------------------------------
- Copying arr1 to arr3     : O(n)
- Copying arr2 to arr3     : O(m)
- Printing arrays          : O(n + m)

Space Complexity:
----------------------------------------------------------------------------
- O(n + m) for storing merged elements in arr3.

Limitations:
----------------------------------------------------------------------------
- Static size arrays; no use of dynamic memory (e.g., malloc).

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

// Function to display elements of an array
void show(int arr[], int s) {
    // Loop through the array from index 0 to s-1
    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]); // Print each element followed by a space
    }
    printf("\n"); // Print newline after printing the array
}

int main() {
    // Initialize two arrays with values
    int arr1 [] = {1, 2, 3, 4, 5};       // First array with 5 elements
    int arr2 [] = {6, 7, 8, 9};          // Second array with 4 elements
    int size_arr1 = 5, size_arr2 = 4;    // Sizes of both arrays

    // Create a third array with size equal to sum of both arrays
    int arr3[size_arr1 + size_arr2];     // arr3 will store the merged result

    // Print the first array
    printf("Array arr1: ");
    show(arr1, size_arr1);

    // Print the second array
    printf("Array arr2: ");
    show(arr2, size_arr2);

    // Merge first array (arr1) into arr3
    for (int i = 0; i < size_arr1; i++) {
        arr3[i] = arr1[i]; // Copy each element from arr1 to arr3
    }

    // Merge second array (arr2) into arr3 after arr1's elements
    for (int i = 0; i < size_arr2; i++) {
        arr3[size_arr1 + i] = arr2[i]; // Start placing arr2 after arr1's last index
    }

    // Print the merged array
    printf("Merged Array: ");
    show(arr3, size_arr1 + size_arr2);

    return 0; // End of program
}
