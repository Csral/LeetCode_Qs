My first solution:
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        placed = False
        prev = False
        ctr = 0
        l = len(flowerbed)

        if l == 1:
            return (n < 2 and flowerbed[0] == 0) or (n == 0)

        for i in range(len(flowerbed)):
            if i == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                ctr += 1
                prev = True
                continue

            elif i == len(flowerbed)-1:

                if not prev and flowerbed[i] == 0:
                    ctr += 1
                    prev = True
                    break

            else:

                if prev:
                    prev = False
                    continue

                if flowerbed[i] == 0 and flowerbed[i+1] == 0:
                    prev = True
                    ctr += 1
                    continue
            
            prev = (flowerbed[i] == 1)

        return ctr >= n
```
> took 11 ms on leetcode. Yes, it uses a lot of memory movement! Prev is redundant.
> If i think of it right, prev is a random address - not cached easily. But flowerbed is easily cached!
> CPU loads nearby memory anyway! Also i = 0 can be short circuited!

So:
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        placed = False
        prev = False
        ctr = 0
        l = len(flowerbed)

        if n == 0:
            return True
        elif l == 1:
            return (n < 2 and flowerbed[0] == 0) or (n == 0)

        for i in range(l):
            if i == 0:
                if not (flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                
                continue    

            elif i == l-1:

                if not (flowerbed[i-1] or flowerbed[i]):
                    ctr += 1
                    break

            else:

                # if flowerbed[i-1] == 1:
                #     continue

                if not (flowerbed[i-1] or flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                    continue

        return ctr >= n
```
> But this is 9-11ms - slower. Maybe variable l is the issue? I don't know the reasoning.
So:
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        ctr = 0
        # l = len(flowerbed)

        if n == 0:
            return True
        elif len(flowerbed) == 1:
            return (n < 2 and flowerbed[0] == 0) or (n == 0)

        for i in range(len(flowerbed)):
            if i == 0:
                if not (flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                
                continue    

            elif i == len(flowerbed)-1:

                if not (flowerbed[i-1] or flowerbed[i]):
                    ctr += 1
                    break

            else:

                # if flowerbed[i-1] == 1:
                #     continue

                if not (flowerbed[i-1] or flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                    continue

        return ctr >= n
```
> 6 ms! Not fast enough. After licking on the silicon its electrons responded to me:
> n = 0 is compared so don't do another OR operation. yes worked.
> but its slower? Why? Yes! ALU. The ALU (Arithmetic Logic Unit) has condition flags —
> Zero (Z), Negative (N), Carry (C), Overflow (O). After any arithmetic, these flags are automatically updated!!
> so its output includes a gt, lt and eq against zero - its a one bit comparison as opposed to doing a not
> A bitwise NOT would have to modify the operand, which is costlier and changes data.
> And python's not (trueness) checks are expensive as they work differently.

So finally:
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        ctr = 0
        # l = len(flowerbed)

        if n == 0:
            return True
        elif len(flowerbed) == 1:
            return (n < 2 and flowerbed[0] == 0)

        for i in range(len(flowerbed)):
            if i == 0:
                if not (flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                
                continue    

            elif i == len(flowerbed)-1:

                if not (flowerbed[i-1] or flowerbed[i]):
                    ctr += 1
                    break

            else:

                # if flowerbed[i-1] == 1:
                #     continue

                if not (flowerbed[i-1] or flowerbed[i] or flowerbed[i+1]):
                    ctr += 1
                    flowerbed[i] = 1
                    continue

        return ctr >= n
```
> its 5 ms. Can't find more optimization spots. Maybe change all not's to comparisons?
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        ctr = 0
        # l = len(flowerbed)

        if n == 0:
            return True
        elif len(flowerbed) == 1:
            return (n < 2 and flowerbed[0] == 0)

        for i in range(len(flowerbed)):
            if i == 0:
                if (flowerbed[i] or flowerbed[i+1]) == 0:
                    ctr += 1
                    flowerbed[i] = 1
                
                continue    

            elif i == len(flowerbed)-1:

                if (flowerbed[i-1] or flowerbed[i]) == 0:
                    ctr += 1
                    break

            else:

                # if flowerbed[i-1] == 1:
                #     continue

                if (flowerbed[i-1] or flowerbed[i] or flowerbed[i+1]) == 0:
                    ctr += 1
                    flowerbed[i] = 1
                    continue

        return ctr >= n
```
Nope - 12 ms. No clue why but sure.
