# Hash Tables

## Hash Table: Supported Operations

Purpose: maintain a (possibly evolving) set of stuff. (transactions,
people + associated data, IP addresses, etc.)

Insert: add new record

Delete: delete existing record

Lookup: check for a particular record

(a "dictionary")

Amazing guarantee: all operations in O(1) time!
- properly implemented
- non-pathological data

## Application

### De-Duplication

Given: a "stream" of objects

Goal: remove duplicates (i.e., keep track of unique objects)
- report unique visitors to website
- avoid duplicates in search results

Solution: when new object x arrives
- lookup x in hash table h
- if not found insert x into H

### 2-Sum Problem

Input: unsorted array A of n integers, target sum t

Goal: determine whether or not there are two numbers x, y in A with x +
y = t

Naive Solution: O(n^2) time via exhaustive search.

Better:
- sort A (O(nlog n) time)
- for each x in A, look for t - x in A via binary search

Amazing:
- insert elements of A into hash table H
- for each x in A, lookup t - x in H -> O(n) time

### Further Immediate Applications

- historical application: symbol tables in compilers
- blocking network traffic
- search algorithms (e.g. game tree exploration)
  - use hash table to avoid exploring any configuration more than once
- etc.

## Implementation

### High-Level Idea

Setup: universe U [e.g. all IP addresses, all names, all chessboard
configurations, etc.]
[generally, REALLY BIG]

Goal: want to maintain evolving set S which belongs to U
[generally, of reasonable size]

Solution:
1. pick n = # of "buckets" with (for simplicity assume |S| doesn't vary
   much)
2. choose a hash function h: U -> {0,1,2,...,n-1}
3. use array A of length n, store x in A[h(x)]

### Naive Solutions

1. Array-based solution [indexed by u]
  - O(1) operations but O(|U|) space
2. List-based solution
  - O(|S|) space but O(|S|) Lookup

### Birthday Paradox

Consider n people with random birthdays (i.e., with each day of the year
equally likely). How large does n need to be before there is at least
50% chance that two people have the same birthday?

The answer is 23.

367 - 100%, 57 - 99%, 187 - 99.99...%

It is pretty counterintuitive but is is because there are a large number
of pairs of people.

**Conclusion: Collision is a fact of life!**

### Resolving Collisions

Collision: distinct x, y in U, such that h(x) = h(y).

Solution #1: (separate) chaining
- keep linked list in each bucket
- given a key/object x, perform insert/delete/lookup in the list in
  A[h(x)]

solution #2: open addressing (only one object per bucket)
- hash function now specific probe sequence h1(x), h2(x), ... (keep
  trying till find open slot)
- examples: linear probing (look consecutively), double hashing (use 2
  hash functions).

Rule of thumb:
- if space is your top concern, use open addressing
- deletion is much trickier for open addressing

## Hash Function

### What Makes a Good Hash Function?

Note: in hash table with chaining, insert is O(1) [insert new object x
at front of list in A[h(x)]

O(list length) for insert/delete [could be anywhere from m/n to m for m
objects]

**Point:** performance depends on the choice of hash function! 
(analogous situa6on with open addressing)

Properties of a "Good" Hash Function
1. Should lead to good performance => i.e., should spread data out (gold
   standard - completely random hashing)
2. Should be easy to store / very fast to evaluate

### Bad Hash Functions

Example: keys = phone numbers (10-digits).
- Terrible hash function: h(x) = first 3 digits of x (i.e., area code)
- Mediocre hash function: h(x) = last 3 digits of x [still vulnerable to
  patterns in last 3 digits]

Example: keys = memory locations. (will be multiples of a power of 2)
- Bad function: h(x) = x mod 1000 (again n = 10^3)
  - All odd buckets guranteed to be empty.

### Quick-and-Dirty Hash Functions

Objects U -> ("hash code" e.g., subroutine to convert strings to integers) -> integers -> ("comparison function" like the mod n function) -> buckets {0,1,...,n-1}

How to choose n = # of buckets
1. Choose n to be prime (within constant factor of # of objects in
   table)
2. Not too close to a power of 2
3. Not too close to a power of 10
