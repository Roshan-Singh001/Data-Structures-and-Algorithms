/*
============================================================================
Name        : Selection Sort in C using Dynamic Memory
Description : This program dynamically allocates an array, accepts user input,
              sorts the array using the Selection Sort algorithm, and prints
              the array before and after sorting.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - Size of the array.
   - Elements of the array.

2. Process:
   - Allocate memory dynamically using malloc().
   - Sort the array using Selection Sort:
       - Find the minimum element from the unsorted part and place it at the
         beginning of the array.

3. Output:
   - Display the original unsorted array.
   - Display the sorted array.

Constraints:
----------------------------------------------------------------------------
- User-defined array size.
- Requires freeing dynamically allocated memory to avoid memory leaks.

Intuition:
----------------------------------------------------------------------------
- Selection sort repeatedly finds the minimum element and places it at the 
  start of the unsorted portion of the array.

Time Complexity:
----------------------------------------------------------------------------
- Best Case: O(n^2)
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

// Selection Sort function
void selection_sort(int *a, int size){
    for (int i = 0; i < size - 1; i++) {
        int minindex = i;

        // Find the index of the minimum element in the remaining array
        for (int j = i + 1; j < size; j++) {
            if (a[minindex] > a[j])
                minindex = j;
        }

        // Swap the found minimum with the current element
        int temp = a[minindex];
        a[minindex] = a[i];
        a[i] = temp;
    } 
}

int main()
{
    int size;

    // Input array size
    printf("Size of the Array: ");
    scanf("%d", &size);

    // Dynamically allocate memory
    int *a = (int*) malloc(size * sizeof(int));

    // Input elements
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Display unsorted array
    printf("\nOriginal Array:");
    show(a, size);

    // Sort the array
    selection_sort(a, size);

    // Display sorted array
    printf("\nSorted Array:");
    show(a, size);

    // Free allocated memory
    free(a);

    return 0;
}
