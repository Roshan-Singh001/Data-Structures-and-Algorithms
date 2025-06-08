/*
============================================================================
Name        : Dynamic Array Implementation in C (Manual Resize Simulation)
Description : This C program demonstrates how to implement a basic dynamic
              array manually using pointers and memory allocation functions
              (`malloc`). It allows users to:
              - Create an array with a user-defined capacity and initial elements.
              - Insert elements at a specified index.
              - Delete elements from a specified index.
              - View the updated array after each operation.

Intuition:
----------------------------------------------------------------------------
Unlike languages like Python or C++'s vector, C doesn't offer built-in dynamic arrays.
To simulate a dynamic array:
- Allocate memory manually using `malloc` with a fixed `total_size`.
- Track current `size` separately (i.e., number of used slots).
- On insertion, shift elements to the right.
- On deletion, shift elements to the left.

Functional Overview:
----------------------------------------------------------------------------
1. **createArray()**
   - Allocates memory for an array of user-defined `total_size`.
   - Reads initial `size` elements from the user.
   - Fails if initial size > total capacity or memory allocation fails.

2. **addElement()**
   - Adds a new element at a specified index (from 0 to `size`).
   - Shifts existing elements to the right to make space.
   - Prevents insertion if array is already full.

3. **deleteElement()**
   - Deletes an element at the specified index (0 to `size-1`).
   - Shifts elements to the left to fill the gap.
   - Prevents deletion if array is empty.

4. **printArray()**
   - Utility function to print current array elements from index 0 to `size-1`.

Edge Cases:
----------------------------------------------------------------------------
- Prevents creation with invalid sizes.
- Detects full array on insertion.
- Detects empty array on deletion.
- Validates index bounds for insert/delete.
- Ensures safe memory management (`malloc`, `free`).

Time Complexity:
----------------------------------------------------------------------------
- Insertion at index i: O(n) in worst case due to shifting.
- Deletion at index i : O(n) due to left shifting.
- Array creation     : O(n) for reading inputs.

Space Complexity:
----------------------------------------------------------------------------
- O(n) for storing up to `total_size` elements.

Limitations:
----------------------------------------------------------------------------
- No automatic resizing like `realloc` or linked structure.
- Once full, no new elements can be added unless space is freed.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Function to print the array elements up to the current size
void printArray(int *arr, int size)
{
    // Loop through the array and print each element
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to create a dynamic array and take initial input from the user
void createArray(int **arr, int *total_size, int *size)
{
    // Ask user for total capacity of the array
    printf("\nEnter Total Size of the array: ");
    scanf("%d", total_size);

    // Ask user how many elements they want to add initially
    printf("Enter Initial Number of Elements: ");
    scanf("%d", size);

    // Check: initial number of elements should not be more than total size
    if (*size > *total_size)
    {
        printf("Initial size cannot be greater than total size.\n");
        *size = 0; // Reset size to zero
        return;
    }

    // Allocate memory dynamically based on total size
    *arr = (int *)malloc(*total_size * sizeof(int));
    if (*arr == NULL)
    {
        // If memory allocation fails, exit the program
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Ask the user to enter values for the initial elements
    for (int i = 0; i < *size; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &((*arr)[i]));
    }

    // Show the array after creation
    printf("Array Created: ");
    printArray(*arr, *size);
}

// Function to add an element to the array at a specific index
void addElement(int *arr, int *size, int total_size)
{
    // Check if the array is already full
    if (*size >= total_size)
    {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    int index, value;

    // Ask the user where (which index) to insert the new element
    printf("Enter the Index (0 to %d): ", *size);
    scanf("%d", &index);

    // Validate index
    if (index < 0 || index > *size)
    {
        printf("Invalid index.\n");
        return;
    }

    // Ask the user what value to insert
    printf("Enter the Value: ");
    scanf("%d", &value);

    // Shift all elements to the right from the index to make space
    for (int i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    // Insert the value at the desired index
    arr[index] = value;

    // Increase the size of the array (number of elements used)
    (*size)++;

    // Show the updated array
    printf("Element Added. Updated Array: ");
    printArray(arr, *size);
}

// Function to delete an element at a specific index from the array
void deleteElement(int *arr, int *size)
{
    // If array has no elements, deletion is not possible
    if (*size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    int index;

    // Ask the user which index to delete
    printf("Enter the index to delete (0 to %d): ", *size - 1);
    scanf("%d", &index);

    // Validate the index
    if (index < 0 || index >= *size)
    {
        printf("Invalid index.\n");
        return;
    }

    // Shift all elements to the left from the deleted index
    for (int i = index; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    // Reduce the number of elements used
    (*size)--;

    // Show the updated array
    printf("Element Deleted. Updated Array: ");
    printArray(arr, *size);
}

// Main function to run the program with a menu
int main()
{
    int *arr = NULL;         // Pointer to hold the dynamic array
    int total_size = 0;      // Total allocated size (capacity)
    int size = 0;            // Current number of elements in array
    char option;             // User's choice from the menu

    while (1) // Infinite loop until user chooses to exit
    {
        // Show the menu options to the user
        printf("\nEnter,\n1. Create an Array\n2. Add element\n3. Delete element\n4. Exit: ");
        scanf(" %c", &option); // Note: space before %c handles newline issues

        switch (option)
        {
        case '1': // Create a new array
            createArray(&arr, &total_size, &size);
            break;

        case '2': // Add an element if array exists
            if (arr == NULL)
                printf("Array not created yet.\n");
            else
                addElement(arr, &size, total_size);
            break;

        case '3': // Delete an element if array exists
            if (arr == NULL)
                printf("Array not created yet.\n");
            else
                deleteElement(arr, &size);
            break;

        case '4': // Exit the program
            free(arr); // Free dynamically allocated memory
            printf("Exiting...\n");
            return 0;

        default: // Handle invalid menu option
            printf("Invalid option.\n");
        }
    }

    return 0;
}

