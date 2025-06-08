# Arrays - Complete Guide

## What is an Array?

An **array** is a data structure that stores a fixed-size sequential collection of elements of the same data type. It allows random access to elements using indices, making it ideal for scenarios requiring frequent access and manipulation of elements.

---

## Types of Arrays

### 1D Array (One-Dimensional Array)

A linear structure of elements stored in a contiguous block of memory.

### 2D Array (Two-Dimensional Array)

An array of arrays that represents data in rows and columns (matrix format).

### Multi-Dimensional Arrays (3D and beyond)

Used for complex data representation like tensors or 3D matrices. Less common but essential in scientific computing, image processing, etc.

---

## Array Operations

| Operation | Description                                          | Time Complexity |
| --------- | ---------------------------------------------------- | --------------- |
| Traverse  | Visit all elements                                   | O(n)            |
| Insertion | Insert at beginning/middle/end (shifting required)   | O(n)            |
| Deletion  | Remove from beginning/middle/end (shifting required) | O(n)            |
| Access    | Access an element via index                          | O(1)            |
| Update    | Change the value of an element                       | O(1)            |
| Search    | Find the position of an element (Linear/Binary)      | O(n) / O(log n) |

---

## Applications of Arrays

- Data storage for lists, tables, matrices
- Image processing (2D pixel grids)
- Buffer management (e.g., keyboard input)
- Lookup tables (e.g., ASCII mappings)
- Sorting & Searching algorithms
- Hashing (open addressing)
- Graphs and Trees (adjacency matrix)
- Dynamic programming (storing subproblem results)

---

## Advantages of Arrays

- Random Access: Constant time access using indices.
- Cache Friendliness: Stored in contiguous memory blocks.
- Code Simplicity: Easy to implement and understand.
- Predictable Memory Use: Fixed size allocation.

## Disadvantages of Arrays

- Fixed Size: Size must be known at compile time (in static arrays).
- Inefficient Insertions/Deletions: Need shifting of elements.
- Wasted Space: Over-allocation can lead to unused memory.
- Homogeneous Data Only: Can't mix different data types.

---

## Language-Specific Array Syntax

| Language   | Declaration Example       |
| ---------- | ------------------------- |
| C          | `int arr[5];`             |
| C++        | `int arr[] = {1, 2, 3};`  |
| Java       | `int[] arr = new int[5];` |
| Python     | `arr = [1, 2, 3, 4]`      |
| JavaScript | `let arr = [1, 2, 3];`    |

---

## Common Algorithms with Arrays

- Linear Search
- Binary Search (Sorted arrays)
- Bubble/Selection/Insertion/Merge/Quick Sort
- Prefix Sum Arrays
- Sliding Window Technique
- Kadane's Algorithm (Max Subarray)
- Matrix Multiplication (2D Arrays)
- Rotations (Left/Right/By k steps)
- Sparse Matrix Compression

---

## Conclusion

Arrays are the foundation of data organization in programming. Mastering arrays and their operations is essential before progressing to advanced data structures like Linked Lists, Stacks, Queues, Trees, and Graphs.

## Code Author

**Roshan Singh**

---

## Additional Resources

- [GeeksforGeeks – Arrays](https://www.geeksforgeeks.org/what-is-array/)
- [Wikipedia - Arrays](https://en.wikipedia.org/wiki/Array_(data_structure))