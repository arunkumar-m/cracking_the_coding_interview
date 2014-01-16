# Universal Hashing

## The Load of a Hash Table

Definition: the load factor of a hash table is:

\alpha := # of objects in hash table / # of buckets of hash table

Which hash table implementation strategy is feasible for load factors
larger than 1?

- only chaining (it doesn't make sense that open addressing can have a
  load factor larger than 1)

Note:
1. \alpha = O(1) is necessary condition for operations to run in
   constant time.
2. With open addressing, need \alpha <<  1

Upshot: for good HT performance, need to control load.

## Pathological Data Sets

Upshot #2: for good HT performance, need a good hash function.

Ideal: use super-clever hash function guaranteed to spread every data
set out evenly.

Problem: DOES NOT EXIST! (for every hash function, there is a
pathological data set)

Reason: fix a hash function h: U -> {0, 1, 2, ... , n - 1} (assume |U|
>> n)

=> ala Pigeonhole Principle, there exists a bucket i such that at least
|U| / n elements of U hash to i under h.

=> if data set drawn only from these, everything collides

## Pathological Data in the Real World

Reference: Crosby and Wallach, USENIX 2003.

Main Point: Can paralyze several real-world systems (network intrusion
detection) by exploiting badly designed hash functions.

- open source
- overly simplistic hash function

(easy to reverse engineer a pathological data set)

## Solutions

1. use a cryptographic hash function (e.g., SHA-2)
  - infeasible to reverse engineer a pathological data set
2. use a randomization
  - design a family H of hash functions such that for any data sets S, 
    "almost all" functions h in H spread S out "pretty evenly". 
    (compare to Quick Sort guarantee)

## Overview of Universal Hashing

Next: details on randomized solution in 3 parts.

Part I: proposed definition of a "good random hash function".

Part II: concrete example of simple + practical functions.

Part III: justification of definition: "good functions" lead to "good
performance"
