/*
 ============================================================================
 Name        : Linear Queue using Dynamic Array in C
 Description : Implements a basic linear queue using a dynamically allocated array.

 Intuition:
 ----------------------------------------------------------------------------
 A Linear Queue operates on the First-In-First-Out (FIFO) principle:
 - Enqueue inserts at the rear (back).
 - Dequeue removes from the front.
 
 In this implementation:
 - A struct holds front, back pointers, size, and a dynamic array.
 - Enqueue fails (overflow) when the back reaches the end of the array.
 - Dequeue fails (underflow) when there are no elements between front and back.
 
 Limitation:
 ----------------------------------------------------------------------------
 - Space is not reused after dequeue (as it's linear, not circular).

 Time Complexities:
 ----------------------------------------------------------------------------
 - Enqueue: O(1)
 - Dequeue: O(1)
 - Show:    O(n) [prints n elements]

 Space Complexity:
 ----------------------------------------------------------------------------
 - O(n) where n is the `size` of the queue (fixed at initialization)

 Example Flow:
 ----------------------------------------------------------------------------
 enqueue(1) → enqueue(2) → enqueue(3)
 queue = [1 2 3]
 dequeue() → removes 1 → queue = [2 3]
 After three dequeues, queue appears empty, but can't reuse slots.

 Author      : Roshan Singh
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linear queue
typedef struct queue {
    int front;  // Points to the position before the first element
    int back;   // Points to the last element
    int size;   // Maximum capacity of the queue
    int *a;     // Dynamic array to store queue elements
} queue;

// Function to display current queue elements
void show(queue *q) {
    // If front and back are the same, the queue is empty
    if (q->front == q->back) {
        printf("\nQueue is empty\n");
        return;
    }

    // Print elements from front+1 to back
    printf("\nQueue elements: ");
    for (int i = q->front + 1; i <= q->back; i++) {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

// Function to insert (enqueue) an element into the queue
void enqueue(queue *q, int data) {
    // Check for overflow: if the back has reached the maximum index
    if (q->back == q->size - 1) {
        printf("\nOverflow: Cannot enqueue %d\n", data);
    } else {
        // Move back pointer and insert the element
        q->back++;
        q->a[q->back] = data;
        show(q);  // Display queue after insertion
    }
}

// Function to remove (dequeue) an element from the queue
void dequeue(queue *q) {
    // Check for underflow: no elements to remove
    if (q->front == q->back) {
        printf("\nUnderflow: Queue is empty\n");
    } else {
        // Move front pointer forward to remove the element
        q->front++;
        printf("\nDequeued: %d\n", q->a[q->front]);
        show(q);  // Display queue after deletion
    }
}

int main() {
    // Allocate memory for the queue structure
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        return 1;
    }

    // Initialize front and back to -1, queue is empty initially
    q->front = -1;
    q->back = -1;
    q->size = 3;

    // Allocate memory for the array to store elements
    q->a = (int *)malloc(q->size * sizeof(int));
    if (!q->a) {
        printf("Memory allocation failed for array\n");
        free(q);
        return 1;
    }

    // Test queue operations
    dequeue(q);            // Should show underflow
    enqueue(q, 1);         // Insert 1
    enqueue(q, 2);         // Insert 2
    enqueue(q, 3);         // Insert 3
    enqueue(q, 4);         // Overflow: queue is full

    dequeue(q);            // Remove 1
    dequeue(q);            // Remove 2
    dequeue(q);            // Remove 3
    dequeue(q);            // Underflow: queue is empty

    enqueue(q, 5);         // Insert 5 (Note: linear queue can't reuse old space)
    enqueue(q, 6);         // Insert 6
    enqueue(q, 7);         // Overflow again if queue was full

    // Free the dynamically allocated memory
    free(q->a);
    free(q);

    return 0;
}
