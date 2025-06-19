/*
============================================================================
Name        : Hash Table with Double Hashing in C
Description : This program implements a hash table using **open addressing**
              with **double hashing** to handle collisions. It supports:
              - Insertion of integers
              - Logical deletion of integers
              - Searching for integers
              - Displaying the full table content

Functional Requirements:
----------------------------------------------------------------------------
1. Insertion using double hashing:
   - Primary hash: h1(key) = key % Table_Size
   - Secondary hash: h2(key) = R - (key % R)
   - Final probe index: (h1 + i * h2) % Table_Size

2. Deletion using DELETED marker to preserve probe sequence.
3. Searching via the double hashing probe sequence.
4. Displaying table with indication of EMPTY, DELETED, or filled slots.

Intuition:
----------------------------------------------------------------------------
- **Double hashing** reduces primary and secondary clustering by using a 
  second hash function to determine the step size for probing.
- Requires the secondary hash function to return values co-prime with the
  table size to ensure full coverage.

Constraints:
----------------------------------------------------------------------------
- Table_Size = 11 (must be prime for better performance)
- R = 7 (must be less than Table_Size and co-prime to it)
- Uses constants: EMPTY = -1, DELETED = -2

Time Complexity:
----------------------------------------------------------------------------
- Average: O(1)
- Worst: O(n), especially in full or nearly full tables

Space Complexity:
----------------------------------------------------------------------------
- O(n) where n = Table_Size

Limitations:
----------------------------------------------------------------------------
- Fixed table size (no dynamic resizing or rehashing)
- Logical deletion doesn't reclaim space immediately
- Performance degrades when load factor is high

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

#define Table_Size 11     // Size of hash table (should be prime)
#define R 7               // Secondary hash constant (must be < Table_Size and co-prime)
#define EMPTY -1          // Indicator for empty slot
#define DELETED -2        // Indicator for deleted slot

int hash_table[Table_Size];  // Array representing the hash table

// Primary hash function
int hash1(int value) {
    return value % Table_Size;
}

// Secondary hash function for step size
int hash2(int value) {
    return R - (value % R);
}

// Display the current state of the hash table
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

// Insert a value using double hashing
void insert(int value) {
    int index = hash1(value);
    int step = hash2(value);
    int original_index = index;
    int i = 0;

    // Probe sequence using double hashing
    while (hash_table[index] != EMPTY && hash_table[index] != DELETED && i < Table_Size) {
        index = (original_index + (i * step)) % Table_Size;
        i++;
    }

    if (i < Table_Size)
        hash_table[index] = value;
    else
        printf("Hash table is full! Cannot insert %d\n", value);
}

// Delete a value (logical deletion)
void delete(int value) {
    int index = hash1(value);
    int step = hash2(value);
    int original_index = index;
    int i = 0;

    // Probe to locate the value
    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value) {
        index = (original_index + (i * step)) % Table_Size;
        i++;
    }

    if (i < Table_Size && hash_table[index] == value)
        hash_table[index] = DELETED;
    else
        printf("\n%d not found in the hash\n", value);
}

// Search for a value in the table
void search(int value) {
    int index = hash1(value);
    int step = hash2(value);
    int original_index = index;
    int i = 0;

    // Probe sequence
    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value) {
        index = (original_index + (i * step)) % Table_Size;
        i++;
    }

    if (i < Table_Size && hash_table[index] == value)
        printf("\n%d found in the hash\n", value);
    else
        printf("\n%d not found in the hash\n", value);
}

// Main function to demonstrate hash table operations
int main() {
    // Initialize the hash table with EMPTY markers
    for (int i = 0; i < Table_Size; i++)
        hash_table[i] = EMPTY;

    // Insert values
    insert(1);
    insert(2);
    insert(3);
    insert(12);
    insert(22);
    insert(32);

    // Display table
    display();

    // Delete operations
    delete(2);     // Valid deletion
    delete(23);    // Not found

    // Display after deletion
    display();

    // Search operations
    search(2);     // Should not be found
    search(22);    // Should be found

    return 0;
}
