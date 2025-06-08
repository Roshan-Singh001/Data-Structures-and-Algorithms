/*
============================================================================
Name        : Optimized Array Rotation in C (Using Temporary Array)
Description : This C program performs efficient **right** and **left** rotations
              on a static array using a temporary array. Unlike basic rotation
              methods with repeated shifts, this version rotates in **O(n)** time.

Intuition:
----------------------------------------------------------------------------
- Basic rotation by shifting elements one-by-one is O(n * k), inefficient for large `k`.
- Optimization idea:
  1. Use a temporary array to store rotated elements.
  2. Calculate the rotated positions using index math and copy accordingly.
  3. Perform `k = k % size` to reduce unnecessary full-circle rotations.

Functional Overview:
----------------------------------------------------------------------------
1. **show()**
   - Utility function to print array elements.

2. **RightRotate()**
   - Stores the last `k` elements in a temporary array.
   - Moves the first `(n-k)` elements to the right.
   - Copies the temporary elements to the start of the array.

3. **LeftRotate()**
   - Stores the first `k` elements in a temporary array.
   - Moves the remaining `(n-k)` elements to the left.
   - Copies the stored elements to the end of the array.

Edge Cases:
----------------------------------------------------------------------------
- Handles `k > size` using `k %= size`.
- No rotation if `k == 0` or `k % size == 0`.
- Avoids data loss and overlapping by using temporary buffer.

Time Complexity:
----------------------------------------------------------------------------
- Both Left and Right Rotation: O(n)
  (One pass for rearranging, one for copying)

Space Complexity:
----------------------------------------------------------------------------
- O(n) extra space for temporary array

Limitations:
----------------------------------------------------------------------------
- Extra space is used; in-place rotation (with reversal or juggling) is possible but not implemented here.
- Array is static and predefined in `main()`.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

// Utility function to display array
void show(int arr[], int s) {
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Optimized Right Rotation using temporary array
void RightRotate(int arr[], int k, int s) {
    printf("\nRight Rotate by %d: \n", k);
    int temp[s];
    k %= s;  // Avoid full unnecessary rotations

    // Copy last k elements to the front of temp
    for (int i = 0; i < k; i++) temp[i] = arr[s - k + i];

    // Copy first (s-k) elements to remaining positions
    for (int i = 0; i < s - k; i++) temp[i + k] = arr[i];

    // Copy temp back to original array
    for (int i = 0; i < s; i++) arr[i] = temp[i];

    show(arr, s);
}

// Optimized Left Rotation using temporary array
void LeftRotate(int arr[], int k, int s) {
    printf("\nLeft Rotate by %d: \n", k);
    int temp[s];
    k %= s;  // Avoid full unnecessary rotations

    // Copy first k elements to the end of temp
    for (int i = 0; i < k; i++) temp[s - k + i] = arr[i];

    // Copy the rest to the beginning
    for (int i = 0; i < s - k; i++) temp[i] = arr[i + k];

    // Copy temp back to original array
    for (int i = 0; i < s; i++) arr[i] = temp[i];

    show(arr, s);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    RightRotate(arr, 2, size);   // Efficient right rotation by 2
    LeftRotate(arr, 7, size);    // Efficient left rotation by 7 (same as 1)

    return 0;
}
