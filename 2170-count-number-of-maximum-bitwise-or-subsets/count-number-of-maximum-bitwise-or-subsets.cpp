class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
                int max_or = 0, count = 0;
        int n = nums.size();

        // Step 1: Calculate the maximum possible bitwise OR
        for (int num : nums) {
            max_or |= num;
        }

        // Step 2: Iterate over all possible subsets
        int total_subsets = 1 << n; // 2^n subsets
        for (int mask = 1; mask < total_subsets; ++mask) {
            int subset_or = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) { // If the ith bit is set, include nums[i] in the subset
                    subset_or |= nums[i];
                }
            }
            // Step 3: If the subset OR equals max OR, increment the count
            if (subset_or == max_or) {
                ++count;
            }
        }

        return count;
    }
};