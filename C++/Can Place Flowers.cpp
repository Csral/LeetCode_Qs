class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int ctr = 0;
        size_t s = flowerbed.size();

        if (n == 0) return true;
        else if (s == 1) return (n < 2 && flowerbed[0] == 0);

        for (size_t i = 0; i < s; i++) {

            if (i == 0) {
                if (!(flowerbed[0] || flowerbed[1])) {
                    ctr++;
                    flowerbed[0] = 1;
                }
                continue;
            } else if (i == s-1) {

                if (!(flowerbed[i-1] || flowerbed[i])) {
                    ctr++;
                    break;
                }

            } else {

                if (!(flowerbed[i-1] || flowerbed[i] || flowerbed[i+1])) {
                    ctr++;
                    flowerbed[i] = 1;
                }
                continue;
            }

        }
        
        return (ctr >= n);

    }
};
