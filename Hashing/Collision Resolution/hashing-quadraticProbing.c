/*
============================================================================
Name        : Hash Table with Quadratic Probing in C
Description : This C program implements a hash table using open addressing 
              with **quadratic probing** to resolve collisions. It allows:
              - Insertion of integers
              - Deletion using logical deletion
              - Searching for elements
              - Displaying hash table content

Functional Requirements:
----------------------------------------------------------------------------
1. Insert values using quadratic probing:
   - Probes with formula: (h + i^2) % Table_Size
2. Delete values by marking them as logically DELETED.
3. Search for values considering EMPTY and DELETED cells.
4. Display the full hash table with index states.

Intuition:
----------------------------------------------------------------------------
- In quadratic probing, instead of checking the next index linearly, the 
  algorithm jumps quadratically (i.e., i^2 steps away), reducing primary
  clustering issues seen in linear probing.

Hashing Strategy:
----------------------------------------------------------------------------
- Primary hash: `index = value % Table_Size`
- Quadratic probing: `index = (original_index + i*i) % Table_Size`

Constraints:
----------------------------------------------------------------------------
- Fixed table size of 10.
- Insertion fails if no slot is available after Table_Size attempts.
- Deleted slots are reused for new insertions.

Time Complexity:
----------------------------------------------------------------------------
- Average case: O(1)
- Worst case: O(n) in case of many collisions or bad distribution

Space Complexity:
----------------------------------------------------------------------------
- O(n), where n = Table_Size

Limitations:
----------------------------------------------------------------------------
- No automatic resizing of the hash table.
- Infinite loops avoided using a fixed number of probing attempts.
- Secondary clustering may still occur.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

#define Table_Size 10     // Size of the hash table
#define EMPTY -1          // Marker for an empty cell
#define DELETED -2        // Marker for a logically deleted cell

int hash_table[Table_Size];

// Hash function (simple modulo)
int hash(int value) {
    return value % Table_Size;
}

// Displays the contents of the hash table
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

// Inserts a value using quadratic probing
void insert(int value) {
    int index = hash(value);
    int original_index = index;
    int i = 0;

    // Try probing up to Table_Size times
    while (hash_table[index] != EMPTY && hash_table[index] != DELETED && i < Table_Size) {
        index = (original_index + (i * i)) % Table_Size;
        i++;
    }

    if (i < Table_Size)
        hash_table[index] = value;
    else
        printf("Hash table is full! Cannot insert %d\n", value);
}

// Deletes a value logically by marking it as DELETED
void delete(int value) {
    int index = hash(value);
    int original_index = index;
    int i = 0;

    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value) {
        index = (original_index + (i * i)) % Table_Size;
        i++;
    }

    if (i < Table_Size && hash_table[index] == value)
        hash_table[index] = DELETED;
    else
        printf("\n%d not found in the hash\n", value);
}

// Searches for a value using quadratic probing
void search(int value) {
    int index = hash(value);
    int original_index = index;
    int i = 0;

    while (i < Table_Size && hash_table[index] != EMPTY && hash_table[index] != value) {
        index = (original_index + (i * i)) % Table_Size;
        i++;
    }

    if (i < Table_Size && hash_table[index] == value)
        printf("\n%d found in the hash\n", value);
    else
        printf("\n%d not found in the hash\n", value);
}

// Main function to demonstrate the hash table operations
int main() {
    // Initialize the table with EMPTY markers
    for (int i = 0; i < Table_Size; i++)
        hash_table[i] = EMPTY;

    // Insert elements
    insert(1);
    insert(2);
    insert(3);
    insert(12);
    insert(22);
    insert(32);

    // Delete a present and an absent element
    delete(2);   // should mark as DELETED
    delete(23);  // not found

    // Display hash table
    display();

    // Search for values
    search(2);   // deleted, should not be found
    search(72);  // not inserted

    // Re-insert 2 into a DELETED slot
    insert(2);

    // Final display
    display();

    return 0;
}
