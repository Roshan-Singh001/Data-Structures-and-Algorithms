/*
============================================================================
Name        : Queue using Two Stacks in C++ (Lazy Transfer)
Description : This program implements a queue using two stacks (`stack1` and `stack2`)
              to simulate FIFO behavior with optimized enqueue and dequeue operations.

Intuition:
----------------------------------------------------------------------------
A **Queue** follows FIFO (First-In-First-Out), but a **Stack** follows LIFO
(Last-In-First-Out). To simulate a queue using stacks:
- `stack1` is used to store newly enqueued elements.
- `stack2` is used for dequeuing in correct FIFO order.
- Elements are moved from `stack1` to `stack2` only when `stack2` is empty.
  This makes the dequeue operation **amortized O(1)**.

How it works:
----------------------------------------------------------------------------
1. **Enqueue(x):**
   - Push the new element directly into `stack1`.
   - No need to rearrange or transfer elements.
   - O(1) time complexity.

2. **Dequeue():**
   - If `stack2` is empty, transfer all elements from `stack1` to `stack2`.
     This reverses the order so the oldest element is on top.
   - Pop the top of `stack2` as the front of the queue.
   - Amortized O(1) time.

3. **Peek():**
   - Returns the front element of the queue.
   - Transfers elements only if `stack2` is empty.

4. **Display():**
   - Copies both stacks to display queue from front to rear.
   - Elements in `stack2` represent the front; `stack1` has the rear in reverse.

Advantages:
----------------------------------------------------------------------------
- Efficient enqueue (O(1)) and amortized O(1) dequeue.
- No element shuffling during enqueue.
- Better than naive version (which does O(n) on each enqueue).

Edge Cases:
----------------------------------------------------------------------------
- Queue Underflow: Both stacks are empty.
- Peek on Empty: Returns informative message.
- Display handles empty and mixed stack states gracefully.

Time Complexity:
----------------------------------------------------------------------------
- Enqueue: O(1)
- Dequeue: Amortized O(1) [because each element is moved at most once]
- Peek   : Amortized O(1)
- Display: O(n) — needs to copy and reverse stacks

Space Complexity:
----------------------------------------------------------------------------
- O(n) — storage in two stacks for n elements

Use Case:
----------------------------------------------------------------------------
- Used in real-time systems where queue operations must be predictable.
- Helpful in implementing task schedulers, inter-process messaging,
  and designing queues using stack-based constraints.

Author      : Roshan Singh
============================================================================
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Two stacks to simulate a queue
stack<int> stack1; // Used for enqueue operations (new elements)
stack<int> stack2; // Used for dequeue operations (reversed elements)

// Function to display current elements in the queue
void display() {
    if (stack1.empty() && stack2.empty()) {
        printf("\nQueue is Empty\n");
        return;
    }

    // Temporary copies of the stacks to preserve original data
    stack<int> s1 = stack1, s2 = stack2;
    vector<int> queueElements;

    // Step 1: Add elements from stack2 (these are front of the queue)
    while (!s2.empty()) {
        queueElements.push_back(s2.top());
        s2.pop();
    }

    // Step 2: Add elements from stack1 in reverse (these are rear of the queue)
    while (!s1.empty()) {
        // Insert at the beginning so that it comes after elements in stack2
        queueElements.insert(queueElements.begin(), s1.top());
        s1.pop();
    }

    // Display final queue elements from front to rear
    printf("\nQueue Elements: ");
    for (int val : queueElements) {
        cout << val << " ";
    }
    printf("\n");
}

// Function to see the front of the queue
void peek() {
    if (stack1.empty() && stack2.empty()) {
        printf("\nQueue is Empty\n");
        return;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    // Now the top of stack2 is the front of the queue
    printf("\nFront Element: %d\n", stack2.top());
}

// Function to add an element to the queue (O(1))
void enqueue(int data) {
    printf("\nEnqueue Element: %d", data);

    // Just push to stack1 (no rearrangement needed)
    stack1.push(data);

    display(); // Optional visualization
}

// Function to remove an element from the queue (amortized O(1))
void dequeue() {
    if (stack1.empty() && stack2.empty()) {
        printf("\nQueue Underflow\n");
        return;
    }

    // If stack2 is empty, move all elements from stack1 to stack2
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    // Top of stack2 is the front of the queue
    printf("\nDequeue Element: %d", stack2.top());
    stack2.pop();

    display(); // Optional visualization
}

int main() {
    enqueue(1);     // Queue: 1
    enqueue(2);     // Queue: 1 2
    enqueue(3);     // Queue: 1 2 3

    peek();         // Should print 1 (front of queue)

    dequeue();      // Removes 1 → Queue: 2 3
    dequeue();      // Removes 2 → Queue: 3
    dequeue();      // Removes 3 → Queue: empty

    dequeue();      // Underflow case
    return 0;
}
