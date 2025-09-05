class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int longest_run = 0;
        bool run = true;
        std::string current = strs[0];
        // strs.erase(strs.begin()); //* Clear it out.

        while (longest_run < current.length() && run) {

            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].length() < longest_run || current[longest_run] != strs[i][longest_run]) {
                    run = false;
                    break;
                }
            }

            if (run)
                longest_run++;

        }
        
        current.resize(longest_run);
        return current;

    }
};
