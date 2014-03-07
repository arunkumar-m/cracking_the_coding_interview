class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        st = []
        for word in s.strip().split(' '):
            if word != '':
                st.append(word)
        st = st[::-1]
        s = ""
        for word in st:
            s += word + " "
        return s.strip()
