/*
============================================================================
Name        : Array Rotation in C (Left and Right Rotations) - Naive Approach
Description : This C program demonstrates how to perform **left** and **right**
              rotations on a static array. Rotations involve shifting elements
              to the left or right by a specific number of positions (`k`).

Intuition:
----------------------------------------------------------------------------
Rotating an array means cyclically shifting its elements:
- **Left Rotation** shifts each element one position to the left, and the first
  element moves to the end.
- **Right Rotation** shifts each element one position to the right, and the
  last element moves to the front.

Functional Overview:
----------------------------------------------------------------------------
1. **show()**
   - Utility function to print array elements.

2. **LeftRotate()**
   - Performs `k` left rotations by:
     a) Storing the first element.
     b) Shifting all other elements to the left.
     c) Placing the first element at the end.
   - Repeats this `k` times.

3. **RightRotate()**
   - Performs `k` right rotations by:
     a) Storing the last element.
     b) Shifting all other elements to the right.
     c) Placing the last element at the beginning.
   - Repeats this `k` times.

Edge Cases:
----------------------------------------------------------------------------
- No rotation if `k == 0`.
- Works correctly for small and moderate `k`, but inefficient for large `k`.
- Doesn't optimize using modulo (`k = k % size`), which would reduce repeated work.

Time Complexity:
----------------------------------------------------------------------------
- LeftRotate / RightRotate: O(k * n)
  For each of the `k` rotations, array shifting takes O(n).

Space Complexity:
----------------------------------------------------------------------------
- O(1) extra space (in-place rotation using one temp variable).

Limitations:
----------------------------------------------------------------------------
- Not optimized for large values of `k` or large arrays.
- Static array only; no dynamic memory handling.
- No use of reverse-based or juggling algorithm for efficient rotation.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

// Utility function to display array elements
void show(int arr[], int s) {
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform left rotation k times
void LeftRotate(int arr[], int k, int s) {
    printf("\nLeft Rotate by %d: \n", k);
    for (int i = 0; i < k; i++) {
        int first = arr[0];  // Store first element

        // Shift all elements to the left
        for (int j = 0; j < s - 1; j++) arr[j] = arr[j + 1];

        arr[s - 1] = first;  // Place first at the end
    }
    show(arr, s);  // Display rotated array
}

// Function to perform right rotation k times
void RightRotate(int arr[], int k, int s) {
    printf("\nRight Rotate by %d: \n", k);
    for (int i = 0; i < k; i++) {
        int last = arr[s - 1];  // Store last element

        // Shift all elements to the right
        for (int j = s - 1; j > 0; j--) arr[j] = arr[j - 1];

        arr[0] = last;  // Place last at the front
    }
    show(arr, s);  // Display rotated array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};           // Original array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of array

    int k = 7;
    LeftRotate(arr, k, size);  // Perform left rotation by 2

    k = 3;
    RightRotate(arr, k, size); // Perform right rotation by 3

    return 0;
}
