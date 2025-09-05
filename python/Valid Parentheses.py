class Solution:

    def isValid(self, s: str) -> bool:
        
        stack = []

        closing = 0
        opening = 0

        if len(s) % 2 != 0:
            return False

        for x in s:
            if x == ')' and (len(stack) == 0 or stack.pop() != '('):
                return False
            elif x == ']' and (len(stack) == 0 or stack.pop() != '['):
                return False
            if x == '}' and (len(stack) == 0 or stack.pop() != '{'):
                return False
            
            if x == '(' or x == '[' or x == '{':
                stack.append(x)

        if len(stack) > 0:
            return False

        return True
