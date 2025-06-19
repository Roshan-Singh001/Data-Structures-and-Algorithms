# Hashing - Complete Guide

## Table of Contents
- [Definition](#definition)
- [Why Use Hashing?](#why-use-hashing)
- [How Hash Functions Work](#how-hash-functions-work)
- [Advantages](#advantages)
- [Disadvantages](#disadvantages)
- [Hash Collisions](#hash-collisions)
- [Collision Resolution Techniques](#collision-resolution-techniques)
  - [Chaining](#chaining)
  - [Open Addressing (Probing)](#open-addressing-probing)
- [Common Hash Functions](#common-hash-functions)
- [Applications](#applications)
- [Performance Analysis](#performance-analysis)
- [Best Practices](#best-practices)

## Definition

**Hashing** is a technique used to map data of arbitrary size to fixed-size values using a mathematical function called a **hash function**. The output of a hash function is called a **hash value**, **hash code**, or simply a **hash**.

A hash function `h(k)` takes a key `k` as input and produces an integer output that typically serves as an index into an array or table.

```
h: Keys → {0, 1, 2, ..., m-1}
```

Where `m` is the size of the hash table.

## Why Use Hashing?

Hashing provides an efficient way to store and retrieve data by converting keys into array indices. Instead of searching through data sequentially, hashing allows direct access to data locations, making operations much faster.

**Key Benefits:**
- **Fast Access**: Average O(1) time complexity for search, insert, and delete operations
- **Space Efficiency**: Compact storage with direct indexing
- **Uniform Distribution**: Good hash functions distribute data evenly
- **Versatility**: Works with various data types as keys

## How Hash Functions Work

A hash function takes an input (key) and produces a hash value that serves as an index:

1. **Input**: Key (string, number, object, etc.)
2. **Processing**: Mathematical computation on the key
3. **Output**: Hash value (typically an integer within a specific range)
4. **Mapping**: Use hash value as index in hash table

**Example:**
```
Key: "apple" → Hash Function → Hash Value: 7 → Index: 7
```

## Advantages

### 1. **Constant Time Operations**
- Average O(1) time complexity for insertion, deletion, and lookup
- Much faster than linear search O(n) or binary search O(log n)

### 2. **Space Efficiency**
- Direct indexing eliminates need for additional pointers or links
- Compact memory usage when load factor is optimized

### 3. **Flexibility**
- Can handle various data types as keys
- Adaptable to different applications and requirements

### 4. **Uniform Distribution**
- Good hash functions spread data evenly across the table
- Minimizes clustering and improves performance

## Disadvantages

### 1. **Hash Collisions**
- Multiple keys may map to the same hash value
- Requires additional handling mechanisms

### 2. **Space Overhead**
- Hash tables often need extra space to maintain low load factor
- Some slots may remain empty, wasting memory

### 3. **Poor Worst-Case Performance**
- Worst-case time complexity can degrade to O(n)
- Occurs when many collisions happen

### 4. **No Ordering**
- Hash tables don't maintain key order
- Cannot efficiently find minimum/maximum or perform range queries

### 5. **Hash Function Dependency**
- Performance heavily depends on quality of hash function
- Poor hash functions can cause clustering and performance issues

## Hash Collisions

A **collision** occurs when two different keys produce the same hash value:

```
h(key1) = h(key2) where key1 ≠ key2
```

**Example:**
```
h("cat") = 5
h("dog") = 5  ← Collision!
```

Collisions are inevitable due to the **Pigeonhole Principle** - when you have more keys than available slots, some slots must contain multiple keys.

## Collision Resolution Techniques

### Chaining

**Chaining** (also called **Separate Chaining**) stores multiple elements that hash to the same index in a linked list at that index.

#### How it Works:
1. Each slot in the hash table contains a pointer to a linked list
2. When collision occurs, new element is added to the list
3. Search requires traversing the appropriate list

#### Example:
```
Index 0: NULL
Index 1: ["apple"] → ["grape"] → NULL
Index 2: ["banana"] → NULL
Index 3: NULL
Index 4: ["orange"] → ["mango"] → NULL
```

#### Advantages:
- Simple to implement
- Hash table never gets "full"
- Less sensitive to hash function quality
- Easy deletion

#### Disadvantages:
- Extra memory for pointers
- Cache performance may suffer due to linked list traversal
- Worst case: O(n) if all keys hash to same index

### Open Addressing (Probing)

**Open Addressing** resolves collisions by finding alternative slots within the hash table itself.

#### Linear Probing
When collision occurs, search for next available slot sequentially.

**Formula:** `h(k, i) = (h'(k) + i) mod m`

Where:
- `h'(k)` is auxiliary hash function
- `i` is probe number (0, 1, 2, ...)
- `m` is table size

**Example:**
```
Insert key with hash value 3:
Index 3 occupied → try index 4
Index 4 occupied → try index 5
Index 5 empty → insert here
```

#### Quadratic Probing
Uses quadratic function to find next slot.

**Formula:** `h(k, i) = (h'(k) + c₁i + c₂i²) mod m`

**Example:**
```
Probe sequence: h'(k), h'(k)+1, h'(k)+4, h'(k)+9, h'(k)+16, ...
```

#### Double Hashing
Uses second hash function to determine step size.

**Formula:** `h(k, i) = (h₁(k) + i × h₂(k)) mod m`

**Example:**
```
h₁(k) = k mod 7
h₂(k) = 1 + (k mod 5)
```

#### Advantages of Open Addressing:
- Better cache performance
- No extra memory for pointers
- All elements stored in table itself

#### Disadvantages of Open Addressing:
- Table can become full
- Clustering can occur (especially linear probing)
- Deletion is complex
- Performance degrades as load factor increases

## Common Hash Functions

### 1. **Division Method**
```
h(k) = k mod m
```
Choose `m` as prime number not close to power of 2.

### 2. **Multiplication Method**
```
h(k) = floor(m × (k × A mod 1))
```
Where `A` is constant (0 < A < 1), often `A = (√5 - 1)/2`.

### 3. **Universal Hashing**
```
h(k) = ((a × k + b) mod p) mod m
```
Where `p` is prime > universe size, `a` and `b` are random.

### 4. **String Hashing**
```python
def hash_string(s, m):
    hash_value = 0
    for char in s:
        hash_value = (hash_value * 31 + ord(char)) % m
    return hash_value
```

## Applications

### 1. **Database Indexing**
- Hash indexes for fast record retrieval
- Used in database management systems

### 2. **Caching**
- Web browsers cache frequently accessed pages
- CPU caches use hash tables for quick lookup

### 3. **Cryptography**
- Password storage (with salt)
- Digital signatures and certificates
- Blockchain and cryptocurrency

### 4. **Compilers**
- Symbol tables for variable and function names
- Keyword recognition

### 5. **Data Structures**
- Hash sets and hash maps
- Implementing dictionaries in programming languages

### 6. **Distributed Systems**
- Consistent hashing for load balancing
- Distributed hash tables (DHT)

### 7. **Network Security**
- Firewall rule matching
- Intrusion detection systems

### 8. **File Systems**
- Git version control system
- File deduplication

## Performance Analysis

### Time Complexity

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Search    | O(1)         | O(n)       |
| Insert    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |

### Space Complexity
- **Chaining**: O(n + m) where n = number of elements, m = table size
- **Open Addressing**: O(m) where m ≥ n

### Load Factor
**Load Factor (α) = n/m**

- **Chaining**: Can exceed 1, typically kept around 0.75
- **Open Addressing**: Must be < 1, typically kept around 0.5


## Best Practices

### 1. **Choose Good Hash Functions**
- Distribute keys uniformly
- Fast to compute
- Use prime numbers for table sizes

### 2. **Manage Load Factor**
- Keep load factor reasonable (0.5-0.75)
- Resize table when load factor gets too high

### 3. **Handle Collisions Appropriately**
- Choose collision resolution based on use case
- Consider memory vs. performance trade-offs

### 4. **Security Considerations**
- Use cryptographic hash functions for security applications
- Be aware of hash collision attacks

### 5. **Testing and Monitoring**
- Monitor collision rates
- Test with realistic data distributions
- Profile performance under different conditions


## Code Author

**Roshan Singh**