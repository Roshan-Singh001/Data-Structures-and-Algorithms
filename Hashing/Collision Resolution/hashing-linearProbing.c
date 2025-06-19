/*
============================================================================
Name        : Hash Table with Linear Probing in C
Description : This C program implements a simple hash table using **open
              addressing** with **linear probing** for collision resolution.
              It supports:
              - Insertion
              - Deletion (using a special DELETED marker)
              - Searching
              - Displaying the table

Functional Requirements:
----------------------------------------------------------------------------
1. Insert an integer into the hash table.
2. Delete an integer using logical deletion (mark as DELETED).
3. Search for an integer in the table.
4. Display all indices of the hash table.

Intuition:
----------------------------------------------------------------------------
- Hash tables are used to achieve average-case O(1) time complexity for
  insert, delete, and search operations.
- Linear probing handles collisions by placing the collided item in the next
  available slot (wrapping around).
- Deletion is done logically by marking the slot as DELETED, preserving
  probing chains.

Hashing Formula:
----------------------------------------------------------------------------
- Primary hash function: `index = value % Table_Size`
- Linear probing: `index = (original_index + i) % Table_Size`

Constraints:
----------------------------------------------------------------------------
- Fixed-size hash table.
- DELETED cells must be considered during insert/search.
- Full table results in insertion failure.

Time Complexity:
----------------------------------------------------------------------------
- Best case: O(1)
- Worst case: O(n) in case of clustering due to linear probing

Space Complexity:
----------------------------------------------------------------------------
- O(n), where n is the table size.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

#define Table_Size 10     // Maximum size of the hash table
#define EMPTY -1          // Empty cell marker
#define DELETED -2        // Deleted cell marker

int hash_table[Table_Size];  // The actual hash table

// Hash function (simple modulo-based)
int hash(int value){
    return value % Table_Size;
}

// Function to display the current state of the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < Table_Size; i++) {
        if (hash_table[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else if (hash_table[i] == DELETED)
            printf("Index %d: DELETED\n", i);
        else
            printf("Index %d: %d\n", i, hash_table[i]);
    }
}

// Function to insert a value into the hash table using linear probing
void insert(int value){
    int index = hash(value);
    int original_index = index;
    int i = 0;

    // Probe until an EMPTY or DELETED slot is found
    while (hash_table[index] != EMPTY && hash_table[index] != DELETED && i < Table_Size)
        index = (original_index + ++i) % Table_Size;

    if (i < Table_Size)
        hash_table[index] = value;
    else
        printf("Hash table is full! Cannot insert %d\n", value);
}

// Function to delete a value from the hash table (logical deletion)
void delete(int value){
    int index = hash(value);
    int original_index = index;
    int i = 0;

    // Probe to find the value or an EMPTY slot
    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value)
        index = (original_index + ++i) % Table_Size;

    if (i < Table_Size && hash_table[index] == value)
        hash_table[index] = DELETED;
    else
        printf("\n%d not found in the hash\n", value);
}

// Function to search a value in the hash table
void search(int value){
    int index = hash(value);
    int original_index = index;
    int i = 0;

    // Probe until found or confirmed not present
    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value)
        index = (original_index + ++i) % Table_Size;

    if (i < Table_Size && hash_table[index] == value)
        printf("\n%d found in the hash\n", value);
    else
        printf("\n%d not found in the hash\n", value);
}

// Driver function to test hash table operations
int main(){
    // Initialize hash table
    for (int i = 0; i < Table_Size; i++)
        hash_table[i] = EMPTY;

    // Insert elements
    insert(1);
    insert(2);
    insert(3);
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);
    insert(62);
    insert(72); // Table is now full

    // Delete some elements
    delete(2);     // Exists
    delete(23);    // Doesn't exist

    // Display current table
    display();

    // Search operations
    search(2);     // Should not be found
    search(72);    // Should be found

    return 0;
}
