/*
 * =====================================================================================
 *
 *       Filename:  longest_palindrome.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 23:44:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool isPal(string s) {
    int begin = 0;
    int end = s.length() - 1;
    while (begin < end) {
        if (s[begin] != s[end]) {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

string expandAroundCenter(string s, int c1, int c2) {
    int l = c1, r = c2;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
    }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    if (s.length() == 0) return "";
    string longest = s.substr(0, 1);
    for (int i = 0; i < s.length() - 1; i++) {
        // odd
        string str1 = expandAroundCenter(s, i, i);
        if (str1.length() > longest.length()) longest = str1;
        // even 
        string str2 = expandAroundCenter(s, i, i + 1);
        if (str2.length() > longest.length()) longest = str2;
    }
    return longest;
}

int main() {
    cout << longestPalindrome("rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip") << endl;
    cout << longestPalindrome("a") << endl;
    return 0;
}
