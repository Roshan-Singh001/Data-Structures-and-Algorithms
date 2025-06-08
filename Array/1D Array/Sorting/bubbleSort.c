/*
============================================================================
Name        : Bubble Sort in C using Dynamic Memory
Description : This program dynamically allocates an array, accepts user input,
              sorts the array using the Bubble Sort algorithm, and prints the
              array before and after sorting.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - Size of the array.
   - Elements of the array.

2. Process:
   - Dynamically allocate memory using malloc().
   - Sort the array using Bubble Sort:
       - Repeatedly swap adjacent elements if they are in the wrong order.

3. Output:
   - Original array before sorting.
   - Sorted array after Bubble Sort.

Constraints:
----------------------------------------------------------------------------
- User-defined array size.
- Requires freeing the dynamically allocated memory.

Intuition:
----------------------------------------------------------------------------
- Bubble sort is a comparison-based algorithm where larger elements "bubble up" to the end.
- Outer loop fixes the sorted position from the end.
- Inner loop compares adjacent pairs.

Time Complexity:
----------------------------------------------------------------------------
- Best Case: O(n)         (if already sorted, with optimization)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
----------------------------------------------------------------------------
- O(1) (in-place sort, except dynamic input)

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void show(int a[], int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

// Bubble Sort implementation
void bubble_sort(int *a, int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // Swapping
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int size;

    // Taking array size as input
    printf("Size of the Array: ");
    scanf("%d", &size);

    // Dynamically allocating memory
    int *a = (int*) malloc(size * sizeof(int));

    // Taking array elements as input
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Displaying original array
    printf("\nOriginal Array:");
    show(a, size);

    // Sorting
    bubble_sort(a, size);

    // Displaying sorted array
    printf("\nSorted Array:");
    show(a, size);

    // Freeing allocated memory
    free(a);

    return 0;
}
