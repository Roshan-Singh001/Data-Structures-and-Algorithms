/*
============================================================================
Name        : In-Place Array Rotation in C using Juggling Algorithm
Description : This C program implements the **Juggling Algorithm** to rotate 
              an array to the left or right in-place with **O(n)** time and 
              **O(1)** space complexity.

Intuition:
----------------------------------------------------------------------------
- The Juggling Algorithm divides the array into `gcd(n, k)` cycles.
- Each element is shifted `k` steps at a time.
- It rotates the array efficiently **without any extra array** (unlike temp-buffer based solutions).

Mathematical Insight:
----------------------------------------------------------------------------
- Total number of cycles = gcd(n, k)
- Each cycle shifts elements by `k` positions.
- Right rotation uses index: `(j - k + n) % n`
- Left rotation uses index:  `(j + k) % n`

Functional Overview:
----------------------------------------------------------------------------
1. **gcd()**
   - Calculates the Greatest Common Divisor (GCD) using Euclidean algorithm.

2. **show()**
   - Utility function to display array contents.

3. **RightRotate()**
   - Rotates array right by `k` using juggling algorithm.
   - Performs rotation in-place by following `gcd(n, k)` cycles.

4. **LeftRotate()**
   - Rotates array left by `k` using juggling algorithm.
   - Works similarly but follows forward cycle direction.

Edge Cases:
----------------------------------------------------------------------------
- Handles `k > n` using `k %= n`
- Detects and optimizes `k == 0` and `k % n == 0` (no rotation)
- In-place, no additional memory used

Time Complexity:
----------------------------------------------------------------------------
- O(n) for both Left and Right rotations
  (Each element is visited exactly once)

Space Complexity:
----------------------------------------------------------------------------
- O(1) extra space (in-place)

Limitations:
----------------------------------------------------------------------------
- Rotation logic assumes array is modifiable and indexable
- Rotation direction logic must be handled carefully to avoid off-by-one errors

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

// Utility function to print array
void show(int arr[], int s) {
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Function to calculate GCD using Euclidean algorithm
int gcd(int s, int k) {
    while (k != 0) {
        int temp = s;
        s = k;
        k = temp % k;
    }
    return s;
}

// In-place Right Rotation using Juggling Algorithm
void RightRotate(int arr[], int s, int k) {
    printf("\nRight Rotate by %d: \n", k);
    k %= s; // Reduce unnecessary rotations
    int cycles = gcd(s, k);

    for (int i = 0; i < cycles; i++) {
        int j = i;
        int temp = arr[i];

        while (1) {
            int l = (j - k + s) % s;
            if (l == i) break;
            arr[j] = arr[l];
            j = l;
        }
        arr[j] = temp;
    }

    show(arr, s);
}

// In-place Left Rotation using Juggling Algorithm
void LeftRotate(int arr[], int s, int k) {
    printf("\nLeft Rotate by %d: \n", k);
    k %= s;
    int cycles = gcd(s, k);

    for (int i = 0; i < cycles; i++) {
        int j = i;
        int temp = arr[i];

        while (1) {
            int l = (j + k) % s;
            if (l == i) break;
            arr[j] = arr[l];
            j = l;
        }
        arr[j] = temp;
    }

    show(arr, s);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    RightRotate(arr, size, 2);   // Right rotate by 2
    LeftRotate(arr, size, 8);    // Left rotate by 8 (same as 2)

    return 0;
}
