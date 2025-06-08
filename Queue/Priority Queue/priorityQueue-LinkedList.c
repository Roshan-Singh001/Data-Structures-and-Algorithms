/*
 ============================================================================
 Name        : Priority Queue using Linked List in C
 Description : This program implements a Priority Queue using a singly linked list.

 Intuition:
 ----------------------------------------------------------------------------
 A Priority Queue is a special type of queue where each element is associated
 with a priority, and elements are served based on their priority — not just
 their order in the queue. In this implementation, higher priority numbers
 mean higher importance.

 For example:
 If you enqueue elements like (data=5, priority=1), (data=3, priority=3), and
 (data=4, priority=2), the queue will arrange them as:
     (3, priority=3) -> (4, priority=2) -> (5, priority=1)

 Key Operations:
 ----------------------------------------------------------------------------
 1. Enqueue: Insert a new element in the queue based on its priority so that
             the highest priority is always at the front. - O(n)
 2. Dequeue: Remove the element from the front (i.e., the one with the highest priority). - O(1)
 3. Peek   : View the element at the front without removing it. - O(1)
 4. Display: Show the current elements of the queue in order of their priority.

 Why Linked List?
 ----------------------------------------------------------------------------
 Using a linked list allows dynamic memory allocation, avoiding a fixed size
 as in arrays. It also makes insertion based on priority easier since we can
 insert at any position.

 Author      : Roshan Singh
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure for each node in the priority queue
typedef struct Node
{
    int data;           // Value of the element
    int priority;       // Priority of the element (higher value = higher priority)
    struct Node *next;  // Pointer to the next node
} Node;

Node *front = NULL;     // Front pointer to track the highest priority node in the queue

// Function to view the element at the front of the queue without removing it
void peek()
{
    if (front == NULL)
        printf("\nQueue is empty\n");
    else
        printf("\nFront Element: %d, Priority: %d\n", front->data, front->priority);
}

// Function to display all elements of the queue along with their priorities
void display()
{
    if (front == NULL)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue Elements: \n");
    Node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d %d-P ", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to insert a new element into the priority queue
void enqueue(int data, int priority)
{
    // Create a new node with given data and priority
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("\nQueue Overflow: Memory allocation failed.\n");
        return;
    }
    node->data = data;
    node->priority = priority;
    node->next = NULL;

    printf("\nEnqueue Element: %d, Priority- %d", data, priority);

    // If queue is empty or new node has higher priority than front node
    if (front == NULL || front->priority < priority)
    {
        node->next = front;
        front = node; // Insert at the front
    }
    else
    {
        // Traverse to find the position to insert the new node based on priority
        Node *ptr = front;
        while (ptr->next != NULL && ptr->next->priority >= priority)
            ptr = ptr->next;

        // Insert the node in its correct position
        node->next = ptr->next;
        ptr->next = node;
    }
    display(); // Show updated queue
}

// Function to remove the element with the highest priority (i.e., front node)
void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nDequeue Element: %d Highest Priority- %d", front->data, front->priority);

    // Remove the front node
    Node *temp = front;
    front = front->next;
    free(temp);

    display(); // Show updated queue
}

// Main function to test priority queue operations
int main()
{
    // Insert elements into the queue
    enqueue(1, 10);
    enqueue(2, 6);
    enqueue(3, 3);
    enqueue(4, 11);
    enqueue(5, 5);

    // Remove elements from the queue one by one
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // Attempt to dequeue from an empty queue
    dequeue();

    return 0;
}
