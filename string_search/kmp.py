# S is an array of characters to be searched
# W is the word sought
# T is the partial match table
# Output is an integer (zero-based position in S at which W is found
def kmp(S, W, T):
    m = 0 # the beginning of the current match in S
    i = 0 # the position of the current character in W
    while m + i < len(S):
        if W[i] == S[m + i]:
            if i == len(W) - 1:
                return m
            i += 1
        else:
            m = m + i - T[i]
            if T[i] > -1:
                i = T[i]
            else:
                i = 0
    return len(S)

kmp('abcabcdababcabcdabde', 'abcdabd', [-1,0,0,0,0,1,2])

# TODO
# Calculate the partial match table
