/*
===============================================================================
 Name        : Circular DEque (Double-Ended Queue) Using Array in C
 Description : Implementation of a double-ended circular queue using fixed-size array.

 Intuition:
-------------------------------------------------------------------------------
- A DEque allows insertion and deletion at both front and rear.
- Using a circular array helps efficiently wrap around when inserting at the front
  or deleting from the rear, avoiding memory wastage.
- We track the front and rear indices using modular arithmetic.

Edge Cases:
-------------------------------------------------------------------------------
- Empty Queue: front == -1
- Full Queue: front == (rear + 1) % size
- Single Element: front == rear

Operations:
-------------------------------------------------------------------------------
- insert_front(): Adds element to front, wraps using modulo.
- insert_back(): Adds element to rear, wraps using modulo.
- delete_front(): Removes element from front, wraps using modulo.
- delete_back(): Removes element from rear, wraps using modulo.
- display(): Traverses from front to rear.

Time Complexity:
-------------------------------------------------------------------------------
- All operations (insert/delete/display): O(1) average case
- Display: O(n)

Space Complexity:
-------------------------------------------------------------------------------
- O(n) where n = size of array

Author      : Roshan Singh
===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to represent a circular DEque (Double-Ended Queue)
typedef struct DEque {
    int front;   // Index of front element
    int rear;    // Index of rear element
    int size;    // Maximum size of the deque
    int *a;      // Pointer to the array that stores elements
} DEque;

// Function to display all elements in the deque
void display(DEque *dq){
    if (dq->front == -1) { // If front is -1, deque is empty
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;

    // Loop to print elements from front to rear using circular indexing
    while (1) {
        printf("%d ", dq->a[i]);
        if (dq->rear == i) break; // Stop if we've reached the rear
        i = (i + 1) % dq->size;   // Move to next index in circular manner
    }
    printf("\n");
}

// Function to insert an element at the front of the deque
void insert_front(DEque *dq, int data){
    // Check if deque is full: front is just ahead of rear in circular indexing
    if ((dq->front == (dq->rear + 1) % dq->size)) {
        printf("Overflow !!!\n");
        return;
    }

    // If deque is empty, initialize front and rear to 0
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        // Move front back by one position circularly
        dq->front = (dq->front - 1 + dq->size) % dq->size;
    }

    // Insert the new element
    dq->a[dq->front] = data;
    display(dq); // Show current state
}

// Function to insert an element at the rear (back) of the deque
void insert_back(DEque *dq, int data){
    // Check for overflow (deque is full)
    if ((dq->front == (dq->rear + 1) % dq->size)) {
        printf("Overflow !!!\n");
        return;
    }

    // If deque is empty, initialize front and rear to 0
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        // Move rear forward by one position circularly
        dq->rear = (dq->rear + 1) % dq->size;
    }

    // Insert the new element
    dq->a[dq->rear] = data;
    display(dq);
}

// Function to delete an element from the front of the deque
void delete_front(DEque *dq){
    if(dq->front == -1) { // Check if deque is empty
        printf("Underflow !!!\n");
        return;
    }

    // Print the deleted element
    printf("Deleted element: %d\n", dq->a[dq->front]);

    // If there is only one element, reset deque to empty
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else {
        // Move front forward by one position circularly
        dq->front = (dq->front + 1) % dq->size;
    }

    display(dq);
}

// Function to delete an element from the rear of the deque
void delete_back(DEque *dq){
    if(dq->front == -1) { // Check if deque is empty
        printf("Underflow !!!\n");
        return;
    }

    // Print the deleted element
    printf("Deleted element: %d\n", dq->a[dq->rear]);

    // If there's only one element, reset deque to empty
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else {
        // Move rear backward by one position circularly
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    }

    display(dq);
}

// Main function to test the deque operations
int main(){
    // Allocate memory for the deque structure
    DEque *dq = (DEque*) malloc(sizeof(DEque));
    if (!dq) {
        printf("Memory allocation failed for DEque\n");
        return 1;
    }

    // Initialize deque to empty
    dq->front = -1;
    dq->rear = -1;
    dq->size = 5;

    // Allocate memory for the array that stores elements
    dq->a = (int*) malloc(dq->size * sizeof(int));
    if (!dq->a) {
        printf("Memory allocation failed for array\n");
        free(dq);
        return 1;
    }

    display(dq); // Display empty deque

    // Insert elements at the back
    insert_back(dq, 1);
    insert_back(dq, 3);
    insert_back(dq, 4);
    insert_back(dq, 5);

    // Try inserting at the front (should work once, then overflow)
    insert_front(dq, 6); // This should succeed
    insert_front(dq, 7); // This should print "Overflow"

    // Delete two elements from the back
    delete_back(dq);
    delete_back(dq);
    
    // Delete three elements from the front
    delete_front(dq);
    delete_front(dq);
    delete_front(dq);

    // Free the memory used by deque and array
    free(dq->a);
    free(dq);

    return 0;
}
