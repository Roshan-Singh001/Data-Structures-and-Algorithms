/*
============================================================================
Name        : Simple Hash Table (Without Collision Resolution)
Description : This program implements a basic hash table using a fixed-size 
              array and a simple modulo hash function. It supports:
              - Insertion (no collision resolution)
              - Search
              - Deletion
              - Displaying the hash table

Functional Requirements:
----------------------------------------------------------------------------
1. Insertion:
   - Uses `value % TABLE_SIZE` as hash index.
   - Inserts only if the slot is EMPTY.
   - If collision occurs, insertion is denied (no probing/chaining).

2. Deletion:
   - Marks slot as EMPTY if value matches the hashed index.
   - Otherwise, deletion fails.

3. Search:
   - Checks the hashed index directly.

4. Display:
   - Shows current table content with EMPTY markers.

Constraints:
----------------------------------------------------------------------------
- TABLE_SIZE = 10 (fixed size)
- No collision handling (i.e., no linear probing, chaining, or double hashing)

Time Complexity:
----------------------------------------------------------------------------
- Insert/Search/Delete: O(1) in best case
- No retry or rehashing on collision

Limitations:
----------------------------------------------------------------------------
- Cannot insert if collision occurs
- No handling of duplicate values
- Not suitable for dense data or large datasets

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Simple modulo-based hash function
int hash(int value) {
    return value % TABLE_SIZE;
}

// Insert a value (fails on collision)
void insert(int value) {
    int index = hash(value);
    if (hashTable[index] == EMPTY) {
        hashTable[index] = value;
        printf("Inserted %d at index %d\n", value, index);
    } else {
        printf("Collision! Slot at index %d is already occupied by %d. Cannot insert %d\n",
               index, hashTable[index], value);
    }
}

// Search for a value
void search(int value) {
    int index = hash(value);
    if (hashTable[index] == value) {
        printf("Found %d at index %d\n", value, index);
    } else {
        printf("Value %d not found\n", value);
    }
}

// Delete a value
void delete(int value) {
    int index = hash(value);
    if (hashTable[index] == value) {
        hashTable[index] = EMPTY;
        printf("Deleted %d from index %d\n", value, index);
    } else {
        printf("Value %d not found\n", value);
    }
}

// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize all slots to EMPTY
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    // Demonstration
    insert(5);     // index 5
    insert(15);    // index 5 — collision
    insert(3);     // index 3

    display();

    search(15);    // Not found (due to collision)
    search(3);     // Found

    delete(3);     // Delete value at index 3
    display();

    return 0;
}
