class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        ctr = 0
        # l = len(flowerbed)

        if n == 0:
            return True
        elif len(flowerbed) == 1:
            return (n < 2 and flowerbed[0] == 0)

        i = 0

        while i < len(flowerbed):
            if i == 0:
                if (flowerbed[i] or flowerbed[i+1]) == 0:
                    ctr += 1
                    flowerbed[i] = 1
                i += 1
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
                    i += 1
                    continue

            i += 1

        return ctr >= n
