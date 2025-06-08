/*
 ============================================================================
 Name        : Priority Queue using Array in C
 Description : This program implements a simple Priority Queue using a fixed-size array.

 Intuition:
 ----------------------------------------------------------------------------
 A Priority Queue is a data structure where each element has a priority,
 and elements are served based on their priority (highest first), not by
 the order they were added.

 In this implementation:
 - Each element is stored as a pair (value, priority).
 - The queue is stored in an array.
 - On dequeue, we search for the element with the highest priority and remove it.
 - On enqueue, we simply add to the end (if there's space).

 Limitations:
 ----------------------------------------------------------------------------
 - Fixed size (defined by `total_size`)
 - Enqueue is O(1), Dequeue is O(n) due to linear search for the highest priority

 Example:
 Enqueue: (10,3), (20,2), (9,9), (12,9), (30,5)
 Queue becomes: [10->3P, 20->2P, 9->9P, 12->9P, 30->5P]
 Dequeue removes (9->9P) first, then (12->9P), and so on.

 Author      : Roshan Singh
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define total_size 5  // Maximum size of the priority queue

// Structure to hold queue elements with value and priority
typedef struct PriorityQueue {
    int value;      // Data value
    int priority;   // Priority of the value
} queue;

// Global array and size tracker
int size = -1;
queue q[total_size];

// Function to display the queue
void show() {
    if (size == -1) {
        printf("\nNothing in the queue\n");
        return;
    }
    
    printf("\nQueue: ");
    for (int i = 0; i <= size; i++) {
        printf("%d->%dP ", q[i].value, q[i].priority);
    }
    printf("\n");
}

// Function to find the index of the element with the highest priority
int peek() {
    int highestPri = INT_MIN;
    int HPindex = -1;

    for (int i = 0; i <= size; i++) {
        if (q[i].priority > highestPri) {
            highestPri = q[i].priority;
            HPindex = i;
        }
    }

    return HPindex;
}

// Function to insert an element into the priority queue
void enqueue(int value, int priority) {
    if (size >= total_size - 1) {
        printf("\nOverflow: Cannot insert %d->%dP\n", value, priority);
        return;
    }

    size++;  // Increase the size and insert the new element
    q[size].value = value;
    q[size].priority = priority;

    show();  // Display current state of queue
}

// Function to remove the element with the highest priority
void dequeue() {
    if (size == -1) {
        printf("\nUnderflow: Queue is empty\n");
        return;
    }

    int hpindex = peek();  // Find highest priority index

    // Display the removed element
    printf("\nDequeue: %d->%dP\n", q[hpindex].value, q[hpindex].priority);

    // Shift remaining elements to fill the gap
    for (int i = hpindex; i < size; i++) {
        q[i] = q[i + 1];
    }

    size--;  // Decrease size
    show();  // Show updated queue
}

int main() {
    // Insert elements with values and priorities
    enqueue(10, 3);
    enqueue(20, 2);
    enqueue(9, 9);
    enqueue(12, 9);
    enqueue(30, 5);

    // Try inserting beyond capacity
    enqueue(60, 10);
    enqueue(60, 10);

    // Remove elements one by one
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // One more dequeue to test underflow
    dequeue();

    return 0;
}
