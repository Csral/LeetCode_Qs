class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int a,b;

        a = z - x;
        b = z - y;

        if (a < 0) a -= 2*a;
        if (b < 0) b -= 2*b;

        if (a == b) return 0;

        return (a < b) ? 1 : 2;

    }
};
