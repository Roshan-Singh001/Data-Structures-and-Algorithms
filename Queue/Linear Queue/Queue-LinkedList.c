/*
 ============================================================================
 Name        : Queue Using Linked List in C
 Description : Implements a queue using a singly linked list.

 Intuition:
 ----------------------------------------------------------------------------
 A Queue follows the First-In-First-Out (FIFO) principle:
 - `enqueue` inserts at the rear (back).
 - `dequeue` removes from the front.

 This implementation uses dynamic memory (linked list), so it grows as needed.
 - No fixed size limit (like in arrays).
 - Efficient memory use.
 - Overflow only happens if memory can't be allocated.

 Time Complexities:
 ----------------------------------------------------------------------------
 - Enqueue: O(1)     [Insert at back]
 - Dequeue: O(1)     [Remove from front]
 - Show:    O(n)     [Print all elements]

 Space Complexity:
 ----------------------------------------------------------------------------
 - O(n) where n is the number of elements currently in the queue

 Author      : Roshan Singh
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global pointers to the front and back of the queue
Node *front = NULL;
Node *back = NULL;

// Function to display all elements in the queue
void show() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        Node *p = front;
        printf("\nQueue elements: ");
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

// Function to insert an element at the end of the queue
void enqueue(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nQueue Overflow: Memory allocation failed.\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    if (front == NULL) {
        // Queue is empty
        front = back = node;
    } else {
        // Add node at the end
        back->next = node;
        back = node;
    }

    printf("Enqueued: %d\n", data);
    show();
}

// Function to remove an element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow: No elements to dequeue.\n");
        return;
    }

    Node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
        back = NULL; // Reset back if queue is now empty
    }

    free(temp);
    show();
}

// Main function to test the queue
int main() {
    // Test operations
    enqueue(2);
    enqueue(1);
    enqueue(3);
    enqueue(4);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // One more dequeue to test underflow
    dequeue();

    // Final state
    show();

    return 0;
}
