class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        
        a = z - x
        b = z - y

        if a < 0:
            a -= 2*a
        
        if b < 0:
            b -= 2*b

        if a == b:
            return 0

        return 2 if a > b else 1
