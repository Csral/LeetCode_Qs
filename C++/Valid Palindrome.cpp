#include <algorithm>
class Solution {
public:
    bool isPalindrome(string s) {
        
        string m = "";

        for (uint8_t x : s) {
            
            if (x < 48 || (x > 57 && x < 65) || (x > 90 && x < 97) || x > 122) continue;
            if (x >= 65 && x <= 90) x += 32; //* lower case

            m += (char) x;

        }

        string n = m;
        std::reverse(n.begin(), n.end());
        return (m == n);

    }
};
