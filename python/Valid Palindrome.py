class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        m = ""
        s = s.lower().strip()
        
        for x in s:
            if x == "" or not x.isalnum():
                continue
            m += x

        return m[::-1] == m
