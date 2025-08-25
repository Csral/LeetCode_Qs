#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merged;
        int m_size = nums1.size() + nums2.size();
        merged.reserve(m_size + 2);

        for (auto e : nums1) {
            merged.push_back(e);
        }

        for (auto e : nums2) {
            merged.push_back(e);
        }

        /* Sort the merged array */
        std::sort(merged.begin(), merged.end());
        int median_pos = (m_size - 1) / 2;

        if (m_size % 2 == 0)
            return (merged.at(median_pos) + merged.at(median_pos + 1)) / 2.0;
        else
            return merged.at(median_pos);

        // return (m_size % 2 == 0) ?
        //     (merged.at(median_pos) + merged.at(median_pos + 1)) / 2.0 : merged.at(median_pos);

    }
};
