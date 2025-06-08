/*
===============================================================================
 Name        : Doubly Linked List DEque (Double-Ended Queue) in C
 Description : Implementation of a double-ended queue using a doubly linked list.

 Intuition:
-------------------------------------------------------------------------------
- A DEque (Double-Ended Queue) allows insertion and deletion at both ends: 
  front and rear.
- A doubly linked list is ideal for a DEque because it allows:
  → O(1) insertion and deletion at both ends without shifting elements.
- Each node has three fields: 
  → data, 
  → pointer to the next node, 
  → pointer to the previous node.
- We maintain two pointers: 
  → 'front' pointing to the first node,
  → 'rear' pointing to the last node.

Edge Cases:
-------------------------------------------------------------------------------
- Empty Queue: When both front and rear are NULL.
- Single Element: front == rear
- After deletion of all elements: reset both pointers to NULL.

Operations:
-------------------------------------------------------------------------------
- enqueue_front(data): 
    Inserts a new node at the beginning (front) of the DEque.
- enqueue_back(data): 
    Inserts a new node at the end (rear) of the DEque.
- dequeue_front(): 
    Removes a node from the front of the DEque.
- dequeue_back(): 
    Removes a node from the rear of the DEque.
- display(): 
    Traverses and prints all elements from front to rear.

Time Complexity:
-------------------------------------------------------------------------------
- enqueue_front / enqueue_back: O(1)
- dequeue_front / dequeue_back: O(1)
- display: O(n)

Space Complexity:
-------------------------------------------------------------------------------
- O(n), where n = number of elements in the DEque (each node takes space).

Advantages:
-------------------------------------------------------------------------------
- No fixed size limitation like arrays.
- Dynamic memory allocation allows flexibility in queue size.
- Efficient operations at both ends without reallocation or shifting.

Author      : Roshan Singh
===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;               // Data of the node
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
} Node;

// Pointers to the front and rear of the DEque
Node* front = NULL;
Node* rear = NULL;

// Function to display elements from front to rear
void display(){
    if (front == NULL) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nQueue Elements: \n");
    Node* ptr = front;

    // Traverse from front to rear
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to insert an element at the front of the DEque
void enqueue_front(int data){
    // Create new node
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nQueue Overflow\n");
        return;
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    printf("\nEnqueue Front: %d", data);

    // If queue is empty, new node is both front and rear
    if (front == NULL) {
        front = rear = node;
    } else {
        // Insert before the current front
        node->next = front;
        front->prev = node;
        front = node;
    }

    display();
}

// Function to insert an element at the rear (back) of the DEque
void enqueue_back(int data){
    // Create new node
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nQueue Overflow\n");
        return;
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    printf("\nEnqueue Back: %d", data);

    // If queue is empty, new node is both front and rear
    if (front == NULL) {
        front = rear = node;
    } else {
        // Insert after the current rear
        rear->next = node;
        node->prev = rear;
        rear = node;
    }

    display();
}

// Function to delete an element from the front
void dequeue_front(){
    if (front == NULL) {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nDequeue Front: %d", front->data);

    Node* temp = front;
    front = front->next;

    // Update the new front's previous to NULL
    if (front != NULL) {
        front->prev = NULL;
    } else {
        // Queue became empty, update rear as well
        rear = NULL;
    }

    free(temp);
    display();
}

// Function to delete an element from the rear (back)
void dequeue_back(){
    if (rear == NULL) {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nDequeue Back: %d", rear->data);

    Node* temp = rear;
    rear = rear->prev;

    // Update the new rear's next to NULL
    if (rear != NULL) {
        rear->next = NULL;
    } else {
        // Queue became empty, update front as well
        front = NULL;
    }

    free(temp);
    display();
}

// Main function to test the DEque operations
int main(){
    // Insert elements at the front
    enqueue_front(1);
    enqueue_front(2);
    enqueue_front(3);

    // Insert elements at the rear
    enqueue_back(4);
    enqueue_back(5);
    enqueue_back(6);

    // Delete three elements from the front
    dequeue_front();
    dequeue_front();
    dequeue_front();

    // Delete three elements from the back
    dequeue_back();
    dequeue_back();
    dequeue_back();

    // Try to delete from empty queue (should print underflow)
    dequeue_back();

    return 0;
}
