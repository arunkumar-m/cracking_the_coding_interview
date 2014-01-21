"""
Longest palindrome in a given string
"""

def expand(s, i, j):
    """Return the longest palindrome string centered at (i + j) / 2

    >>> expand("adbda", 2, 2)
    'adbda'
    >>> expand("aaaaa", 4, 4)
    'a'
    >>> expand("asdfa", 3, 3)
    'f'
    >>> expand("acbbca", 2, 3)
    'acbbca'

    """
    while i >= 0 and j < len(s) and s[i] == s[j]:
        i -= 1
        j += 1
    return s[i+1:j]


def longestpal(s):
    """Return the longest palindrome in s

    A palindrome mirrors around its center.

    >>> longestpal("a")
    'a'
    >>> longestpal("asdffdsbbb")
    'sdffds'
    >>> longestpal("rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip")
    'qgjjgq'

    """
    longsofar = ""
    # odd
    for i in range(len(s)):
        ret = expand(s, i, i)
        if len(ret) > len(longsofar):
            longsofar = ret
    # even
    for i in range(len(s) - 1):
        ret = expand(s, i, i + 1)
        if len(ret) > len(longsofar):
            longsofar = ret
    return longsofar


if __name__ == '__main__':
    import doctest
    doctest.testmod()
