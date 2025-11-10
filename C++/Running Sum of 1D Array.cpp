class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> res;
        int s = 0;

        for (int num : nums) {
            s += num;
            res.push_back(s);
        }

        return res;

    }
};
