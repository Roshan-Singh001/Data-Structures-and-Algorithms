/*
============================================================================
Name        : Hash Table with Chaining in C
Description : This program implements a hash table using **separate chaining**
              with linked lists to resolve collisions. It supports:
              - Insertion of elements
              - Deletion of elements
              - Searching (fetching) elements
              - Displaying the hash table

Functional Requirements:
----------------------------------------------------------------------------
1. Insert values by computing hash index and adding nodes to a linked list.
2. Delete values by searching the list and updating links.
3. Search values by traversing the corresponding chain.
4. Display full hash table with linked chains at each index.

Constraints:
----------------------------------------------------------------------------
- TABLE_SIZE = 10
- Collision resolution: Separate chaining using singly linked lists
- Uses `malloc` and `free` for dynamic memory management

Advantages:
----------------------------------------------------------------------------
- Easy to implement
- Handles collisions gracefully
- Doesn't require resizing as easily as open addressing

Disadvantages:
----------------------------------------------------------------------------
- Can lead to long chains (performance degrades with clustering)
- Uses extra memory for pointers

Time Complexity (Average Case):
----------------------------------------------------------------------------
- Insert: O(1)
- Delete: O(1)
- Search: O(1)

Time Complexity (Worst Case - all items hashed to same bucket):
----------------------------------------------------------------------------
- Insert/Delete/Search: O(n) where n is the number of elements

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for linked list (used in each bucket)
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Hash table - array of linked list heads
Node* hashTable[TABLE_SIZE];

// Hash function: simple modulo method
int hash(int val) {
    return val % TABLE_SIZE;
}

// Display the entire hash table with chains
void printTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* ptr = hashTable[i];
        while (ptr != NULL) {
            printf("%d -> ", ptr->value);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Insert value into hash table
void insert(int value) {
    int index = hash(value);

    // Create new node
    Node* new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;

    // Insert at head for simplicity
    if (hashTable[index] == NULL)
        hashTable[index] = new;
    else {
        new->next = hashTable[index];
        hashTable[index] = new;
    }
}

// Delete value from hash table
void delete(int value) {
    int index = hash(value);
    Node* ptr = hashTable[index];
    Node* prev = NULL;

    while (ptr != NULL) {
        if (ptr->value == value) {
            if (prev == NULL)
                hashTable[index] = ptr->next; // Remove head node
            else
                prev->next = ptr->next; // Skip current node

            free(ptr);
            printf("\n%d deleted from the Hash\n", value);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    printf("\n%d not found in the Hash\n", value);
}

// Search for value in hash table
void fetch(int value) {
    int index = hash(value);
    Node* ptr = hashTable[index];

    while (ptr != NULL) {
        if (ptr->value == value) {
            printf("\n%d found in the Hash\n", value);
            return;
        }
        ptr = ptr->next;
    }

    printf("\n%d not found in the Hash\n", value);
}

// Main function demonstrating operations
int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    // Insertion
    insert(1);
    insert(2);
    insert(3);
    insert(12);  // Collision with 2
    insert(22);  // Collision with 2

    // Searching
    fetch(1);
    fetch(32);

    // Deletion
    delete(12);

    // Final display
    printTable();

    return 0;
}
