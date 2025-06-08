/*
============================================================================
Name        : Linear Search in C
Description : This program performs a linear (sequential) search on an integer 
              array. It searches for a user-provided value and returns its index 
              if found.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - An integer array.
   - A target value to search.

2. Process:
   - Iterate through each element of the array.
   - Compare each element with the target value.

3. Output:
   - Index of the target value if found.
   - Message indicating "not found" otherwise.

Constraints:
----------------------------------------------------------------------------
- Array does not need to be sorted.
- Linear search checks every element, so it can work on unsorted arrays.

Intuition:
----------------------------------------------------------------------------
- Start from index 0 and scan each element one by one until a match is found.

Time Complexity:
----------------------------------------------------------------------------
- Best Case: O(1)   (element found at the beginning)
- Worst Case: O(n)  (element at end or not present)

Space Complexity:
----------------------------------------------------------------------------
- O(1) (constant space usage)

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};  // Sample array
    int size = 5;               // Number of elements in the array
    int val;                    // Value to search
    int temp = 1;               // Flag to track if value is found

    // User input
    printf("Enter value: ");
    scanf("%d", &val);

    // Linear Search
    for (int i = 0; i < size; i++)
    {
        if (a[i] == val)
        {
            printf("\n%d is found at index %d", val, i);
            temp = 0;
            break;
        }
    }

    // Not Found case
    if (temp)
    {
        printf("\n%d not found", val);
    }

    return 0;
}
