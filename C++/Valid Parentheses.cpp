#include <vector>

class Solution {
public:
    bool isValid(string s) {

        std::vector<char> stack;
        
        if (s.length() % 2 != 0) return false;

        for (auto x : s) {

            if (x == ')') {
                if (stack.size() == 0 || stack.back() != '(') {
                    return false;
                }
                stack.pop_back();
            } else if (x == ']') {
                if (stack.size() == 0 || stack.back() != '[') {
                    return false;
                }
                stack.pop_back();
            } else if (x == '}') {
                if (stack.size() == 0 || stack.back() != '{') {
                    return false;
                }
                stack.pop_back();
            }
            
            if (x == '(' || x == '[' || x == '{')
                stack.push_back(x);

        }

        return !(stack.size() > 0);
    }
};
