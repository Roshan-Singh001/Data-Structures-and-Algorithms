/*
 ============================================================================
 Name        : Circular Queue Using Array in C
 Description : Efficient queue implementation using circular indexing.

 Intuition:
 ----------------------------------------------------------------------------
 A linear queue wastes space when elements are dequeued (front moves forward).
 A circular queue solves this using modular arithmetic:
 - When we reach the end, we wrap around to the beginning.
 - One slot is always left empty to distinguish full from empty state.

 Conditions:
 - Empty: front == back
 - Full : (back + 1) % size == front

 Time Complexities:
 ----------------------------------------------------------------------------
 - Enqueue: O(1)    [Insert at back index]
 - Dequeue: O(1)    [Remove from front index]
 - Show:    O(n)    [Traverse and print current elements]

 Space Complexity:
 ----------------------------------------------------------------------------
 - O(n) where n = queue size (fixed-size array)

 Author      : Roshan Singh
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Define a circular queue structure
typedef struct queue {
    int front;   // Index pointing to the front element
    int back;    // Index pointing to the last inserted element
    int size;    // Maximum capacity of the queue
    int *a;      // Dynamic array to store queue elements
} queue;

// Function to display current queue elements
void show(queue *q) {
    int i = q->front;
    printf("\n");

    // Traverse from front+1 to back (circularly) and print elements
    while (i != q->back) {
        i = (i + 1) % q->size;
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

// Function to add (enqueue) an element to the queue
void enqueue(queue *q, int data) {
    // Check if queue is full: next position of back is front
    if (((q->back + 1) % q->size) == q->front) {
        printf("\nOverflow\n");
    } else {
        // Move back forward circularly and insert new data
        q->back = (q->back + 1) % q->size;
        q->a[q->back] = data;
        show(q); // Display queue after insertion
    }
}

// Function to remove (dequeue) an element from the queue
void dequeue(queue *q) {
    // Check if queue is empty: front and back are equal
    if (q->front == q->back) {
        printf("\nUnderflow\n");
    } else {
        // Move front forward circularly to remove front element
        q->front = (q->front + 1) % q->size;
        show(q); // Display queue after deletion
    }
}

// Main function to test the queue operations
int main() {
    // Allocate memory for the queue structure
    queue *q = (queue*) malloc(sizeof(queue));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        return 1;
    }

    // Initialize front and back pointers and set queue size
    q->front = 0;
    q->back = 0;
    q->size = 5;

    // Allocate memory for queue elements
    q->a = (int*) malloc(q->size * sizeof(int));
    if (!q->a) {
        printf("Memory allocation failed for queue array\n");
        free(q);
        return 1;
    }

    // Test cases for queue
    dequeue(q); // Underflow (queue is empty)

    enqueue(q, 1); // Insert 1
    enqueue(q, 2); // Insert 2
    enqueue(q, 3); // Insert 3
    enqueue(q, 4); // Insert 4
    // At this point, the queue is full

    dequeue(q); // Remove 1st element
    dequeue(q); // Remove 2nd element
    dequeue(q); // Remove 3rd element
    dequeue(q); // Remove 4th element (queue becomes empty)
    dequeue(q); // Underflow (nothing to remove)

    enqueue(q, 25); // Insert after queue has been emptied
    enqueue(q, 25); // Insert again

    // Free allocated memory
    free(q->a);
    free(q);

    return 0;
}
