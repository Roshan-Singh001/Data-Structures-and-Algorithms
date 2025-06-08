/*
============================================================================
Name        : Binary Search Implementation in C
Description : This program performs a binary search on a sorted integer array.
              It determines whether a user-provided element exists in the array
              and, if so, displays its index.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - A partially filled sorted array of integers.
   - An integer element to be searched.

2. Process:
   - Apply binary search algorithm (O(log n)) on the sorted array.
   - Return index if found; else notify not found.

3. Output:
   - Display whether the element exists in the array and its index.

Constraints:
----------------------------------------------------------------------------
- Array must be sorted in ascending order.
- Only `size` number of elements are considered valid in the array.
- Logical size and physical size of array may differ.

Intuition:
----------------------------------------------------------------------------
- Binary search works only on sorted arrays.
- It repeatedly divides the search interval in half and compares the target.

Time Complexity:
----------------------------------------------------------------------------
- Best Case: O(1)  (element is at the middle)
- Worst Case: O(log n)

Space Complexity:
----------------------------------------------------------------------------
- O(1)  (constant space usage)

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

int main()
{
    // Initializing a partially filled array of size 10
    int a[10] = {0, 2, 3, 4, 5};  
    int element;           // Element to be searched
    int size = 5;          // Logical size of the array (since only 5 elements are initialized)
    
    int low = 0, high = size - 1, mid;  
    int temp = 1;          // Flag to indicate whether the element was found

    // Displaying the array
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Taking input from the user
    printf("Enter element: ");
    scanf("%d", &element);
    
    // Binary Search Algorithm
    while (low <= high)
    {
        mid = (low + high) / 2;  // Finding the middle index
        
        if (a[mid] == element)  // Element found
        {
            printf("\n%d is found at %d.", element, mid);
            temp = 0;
            break;
        }
        else if (a[mid] > element)  // Element must be in the left sub-array
            high = mid - 1;
        else  // Element must be in the right sub-array
            low = mid + 1;
    }

    // If element is not found
    if (temp)
    {
        printf("\nNot Found");
    }

    return 0;
}
