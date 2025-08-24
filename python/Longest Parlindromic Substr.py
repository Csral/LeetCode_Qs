class Solution:
    def longestPalindrome(self, s: str) -> str:

        #* Try optimizing later. Very bad for now.
      
        if s == s[::-1]:
            return s;

        record = {}
        
        for i in range(0,len(s)):

            for j in range(len(s) - i):

                test_4 = s[i:len(s)-j]
                test_5 = s[i:len(s)-j-i]

                if test_4 == test_4[::-1]:
                    record[len(test_4)] = test_4
                elif test_5 == test_5[::-1]:
                    record[len(test_5)] = test_5
        
        highest = max(record.keys())
        return record[highest]
