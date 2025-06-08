/*
===============================================================================
 Name        : Circular Queue Using Linked List in C
 Description : A dynamic circular queue where the last node links back to front.

 Intuition:
-------------------------------------------------------------------------------
- A queue follows FIFO (First In First Out).
- A circular linked list lets the `back` node's `next` point to `front`,
  forming a loop, making it circular.
- This avoids memory waste, unlike arrays, and dynamically grows/shrinks.

Special Conditions:
-------------------------------------------------------------------------------
- Empty Queue: front == NULL
- Single Element: front == back, and front->next == front

Operations:
-------------------------------------------------------------------------------
- Enqueue:
    - Create a new node.
    - If empty, make front and back point to new node.
    - Else, insert at back, and make back->next = front.

- Dequeue:
    - If only one node, set front and back to NULL.
    - Else, move front forward and adjust back->next.

Time Complexity:
-------------------------------------------------------------------------------
- Enqueue: O(1)   [Insert at tail]
- Dequeue: O(1)   [Remove from head]
- Display: O(n)   [Traverse until back -> front]

Space Complexity:
-------------------------------------------------------------------------------
- O(n)  [One node per element in queue]

Author      : Roshan Singh
===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the circular queue
typedef struct Node {
    int data;           // To store the actual data
    struct Node* next;  // Pointer to the next node in the queue
} Node;

// Two global pointers to keep track of the front and back of the queue
Node* front = NULL;  
Node* back = NULL;

// Function to display the elements in the circular queue
void display() {
    // If the queue is empty, front will be NULL
    if (front == NULL) {
        printf("\nCircular Queue is empty.\n");
        return;  // Nothing to display, so exit the function
    } else {
        Node* ptr = front;  // Start from the front node
        printf("\nCircular Queue elements: ");
        // Traverse the queue until we come back to the front node
        do {
            printf("%d ", ptr->data);  // Print the current node's data
            ptr = ptr->next;           // Move to the next node
        } while (ptr != front);
    }
    printf("\n");
}

// Function to add an element to the back of the circular queue
void enqueue(int data) {
    // Create a new node with the given data
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {  // Check if memory allocation failed
        printf("\nQueue Overflow: Memory allocation failed.\n");
        return;  // Can't add new element, exit the function
    }

    node->data = data;  // Assign the data to the new node
    node->next = NULL;  // Initially, the next pointer is NULL

    // If queue is empty, initialize front and back to this new node
    if (front == NULL) {
        front = node;
        back = node;
        back->next = front;  // Circular link: back points to front
    } else {
        // If queue is not empty:
        back->next = node;  // The current back node points to the new node
        back = node;        // Update back to the new node
        back->next = front; // Maintain circular link from new back to front
    }

    printf("\nEnqueued: %d", data);
    display();  // Show the updated queue
}

// Function to remove an element from the front of the circular queue
void dequeue() {
    // If queue is empty, can't dequeue
    if (front == NULL) {
        printf("\nQueue Underflow: No elements to dequeue.\n");
        return;
    }

    Node* temp = front;           // Store the node to be removed
    printf("\nDequeued: %d", temp->data);  // Show the value being removed

    // If there's only one node in the queue
    if (front == back) {
        front = NULL;  // Reset front and back to NULL, queue becomes empty
        back = NULL;
        free(temp);    // Free the removed node's memory
    } else {
        // If more than one node exists
        front = front->next;  // Move front pointer to the next node
        back->next = front;   // Maintain circular link from back to new front
        free(temp);           // Free the old front node
    }

    display();  // Show the updated queue after dequeue
}

// Main function to test enqueue and dequeue operations
int main() {
    display();  // Display queue when empty

    enqueue(10);  // Add 10
    enqueue(20);  // Add 20
    enqueue(30);  // Add 30

    dequeue();    // Remove 10
    dequeue();    // Remove 20
    dequeue();    // Remove 30

    dequeue();    // Try to remove from empty queue, should show underflow

    return 0;
}
