class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        longest_run = 0
        run = True
        # Pick the 1st item and match with all other items.

        c = strs[0]

        while longest_run < len(c) and run:

            for x in strs[1:]:
                if longest_run >= len(x):
                    run = False
                    break

                if c[longest_run] != x[longest_run]:
                    run = False
                    break
                    # Even if one doesn't match, break out.
            
            if run:
                longest_run += 1
            
        return c[0:longest_run]
