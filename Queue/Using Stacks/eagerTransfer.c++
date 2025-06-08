/*
============================================================================
Name        : Queue using Two Stacks in C++ (Eager Transfer)
Description : This program implements a simple queue using two stacks:
              - `queueStack` acts as the main stack for queue operations.
              - `helperStack` is used to reorder elements during enqueue.

Intuition:
----------------------------------------------------------------------------
A **Queue** follows FIFO (First-In-First-Out), but a **Stack** follows LIFO
(Last-In-First-Out). To simulate queue behavior using stacks:
- We reverse the order of elements when inserting (enqueue), so that
  the newest element goes to the bottom and the oldest stays on top.
- This way, `top()` of the stack always gives us the front of the queue.

Enqueue Logic:
- While `queueStack` is not empty, move everything to `helperStack`.
- Push the new element into the empty `queueStack`.
- Move everything back from `helperStack` to `queueStack`.
- Now, the new element is at the bottom, and the queue order is preserved.

Dequeue Logic:
- Just `pop()` the top of `queueStack` (acts as the front of the queue).

Peek Logic:
- Returns the front element of the queue (top of `queueStack`).

Display Logic:
- Print all elements in order without modifying the queue structure.

Edge Cases:
----------------------------------------------------------------------------
- Enqueue on empty: direct push to `queueStack`.
- Dequeue on empty: underflow message.
- Peek on empty: handle gracefully.
- Display when empty: show empty message.

Time Complexity:
----------------------------------------------------------------------------
- Enqueue: O(n) — due to moving all elements between stacks.
- Dequeue: O(1) — just pop from `queueStack`.
- Peek   : O(1)
- Display: O(n) — for displaying all elements without losing order.

Space Complexity:
----------------------------------------------------------------------------
- O(n) — additional space used in helperStack during each enqueue.

Use Case:
----------------------------------------------------------------------------
- Simulating queue behavior where only stacks are available.
- Useful for interview problems and concept building.

Author      : Roshan Singh
============================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

// Two stacks to simulate queue behavior
stack<int> queueStack;     // This will always have the front element at the top
stack<int> helperStack;    // Used for intermediate transfers

// Function to display elements in queue order
void display() {
    if (queueStack.empty()) {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue Elements: \n");

    // Step 1: Move elements to helperStack to reverse the order (so we can print front to rear)
    while (!queueStack.empty()) {
        int val = queueStack.top();
        printf("%d ", val);
        queueStack.pop();
        helperStack.push(val);
    }

    // Step 2: Move elements back to queueStack to restore original state
    while (!helperStack.empty()) {
        int val = helperStack.top();
        helperStack.pop();
        queueStack.push(val);
    }
    printf("\n");
}

// Function to view the front of the queue
void peek() {
    if (queueStack.empty()) {
        printf("\nQueue is Empty\n");
        return;
    }
    // Since front of the queue is always at the top of queueStack
    printf("\nValue at front: %d\n", queueStack.top());
}

// Function to add element to queue (enqueue)
// Costly operation: maintains front at top of queueStack
void enqueue(int data) {
    printf("\nEnqueue Element: %d", data);

    // Step 1: Move all elements from queueStack to helperStack
    while (!queueStack.empty()) {
        int val = queueStack.top();
        queueStack.pop();
        helperStack.push(val);
    }

    // Step 2: Push the new element into the empty queueStack
    queueStack.push(data);

    // Step 3: Move everything back from helperStack to queueStack
    // This restores the queue order with the new element at the bottom
    while (!helperStack.empty()) {
        int val = helperStack.top();
        helperStack.pop();
        queueStack.push(val);
    }

    // Optional: Show the current state of the queue
    display();
}

// Function to remove element from queue (dequeue)
void dequeue() {
    if (queueStack.empty()) {
        printf("\nQueue Underflow\n");
        return;
    }
    // Since front is on top of queueStack, just pop it
    printf("\nDequeue Element: %d", queueStack.top());
    queueStack.pop();

    // Optional: Show the current state of the queue
    display();
}

// Main function to test the queue
int main() {
    enqueue(1);     // Queue: 1
    enqueue(2);     // Queue: 1 2
    enqueue(3);     // Queue: 1 2 3

    peek();         // Should print 1

    dequeue();      // Removes 1, Queue: 2 3
    dequeue();      // Removes 2, Queue: 3
    dequeue();      // Removes 3, Queue is empty

    dequeue();      // Underflow case (Queue is already empty)
    return 0;
}

