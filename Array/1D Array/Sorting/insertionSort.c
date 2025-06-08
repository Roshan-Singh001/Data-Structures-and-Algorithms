/*
============================================================================
Name        : Insertion Sort in C using Dynamic Memory
Description : This program dynamically allocates an array, accepts user input,
              sorts the array using the Insertion Sort algorithm, and prints 
              the array before and after sorting.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - Size of the array.
   - Elements of the array.

2. Process:
   - Dynamically allocate memory using malloc().
   - Sort the array using Insertion Sort:
       - Pick elements from the unsorted part and place them in their correct
         position in the sorted part of the array.

3. Output:
   - Original array before sorting.
   - Sorted array after Insertion Sort.

Constraints:
----------------------------------------------------------------------------
- User-defined array size.
- Requires freeing the dynamically allocated memory.

Intuition:
----------------------------------------------------------------------------
- Insertion sort builds the final sorted array one item at a time.
- It is much less efficient on large lists than advanced algorithms like quicksort.

Time Complexity:
----------------------------------------------------------------------------
- Best Case: O(n)         (already sorted)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
----------------------------------------------------------------------------
- O(1) (in-place sorting)

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void show(int a[], int size){
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

// Insertion Sort function
void insertion_sort(int *a, int size){
    for (int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{
    int size;

    // Taking input for size of array
    printf("Size of the Array: ");
    scanf("%d", &size);

    // Dynamic memory allocation
    int *a = (int*) malloc(size * sizeof(int));

    // Input array elements
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Display before sorting
    printf("\nOriginal Array:");
    show(a, size);

    // Sorting the array
    insertion_sort(a, size);

    // Display after sorting
    printf("\nSorted Array:");
    show(a, size);

    // Free the allocated memory
    free(a);

    return 0;
}
