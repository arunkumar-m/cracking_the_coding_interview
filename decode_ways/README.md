# Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1

'B' -> 2

...

'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

## Solution

You can do it using exhaustive search however it is time consuming.

Dynamic programming is a nice solution.

### Dynamic Programming

Let D[i] denotes the number ways of decoding the message.

    D[i] = 0
    D[i] += D[i - 1] if s[i - 1] != '0'
    D[i] += D[i - 2] if i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
