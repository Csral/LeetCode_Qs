class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        """
        
            Since both arrays are sorted, i need to only
            find the index where first element of 2nd array goes
            and then assume they are sorted. But
            this may or may not be the case.

            Max complexity: log(m+n)
            So, merging should be that much more easy...?

            Try sorting raw. = Accepted? But this doesn't
            seem satisfactory. Let's try doing some general optimizations

            After testing, Using quick sort is infact faster.
        
        """

        merged = sorted(nums1 + nums2)
        median = (len(merged) - 1) // 2
        
        if len(merged) % 2 == 0:
            # Median is average
            return (merged[median] + merged[median + 1]) / 2
        else:
            return merged[median]

        # o_pos = 0
        # s_pos = 0

        # while s_pos < len(nums2):

        #     if o_pos >= len(nums1):
        #         nums1.append(nums2[s_pos])
        #         s_pos += 1
        #     elif nums2[s_pos] < nums1[o_pos]:
        #         nums1.insert(o_pos, nums2[s_pos])
        #         s_pos += 1
        #     o_pos += 1

        # print(nums1)

        # median = (len(nums1) - 1) // 2
        
        # if len(nums1) % 2 == 0:
        #     # Median is average
        #     return (nums1[median] + nums1[median + 1]) / 2
        # else:
        #     return nums1[median]
