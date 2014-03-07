class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        st = []
        for word in s.strip().split():
            st.append(word)
        st = st[::-1]
        s = "".join([s + " " for s in st])
        return s.strip()
