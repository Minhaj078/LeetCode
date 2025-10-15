class Solution {
public:

    bool fn(int idx, int t, vector<int>& nums, vector<vector<int>>& dp) {
        if (t == 0) return true;
        if (idx == 0) return (nums[0] == t);
        if (dp[idx][t] != -1) return dp[idx][t];

        bool notTake = fn(idx - 1, t, nums, dp);
        bool take = false;

        if (nums[idx] <= t) {
            take = fn(idx - 1, t - nums[idx], nums, dp);
        }

        return dp[idx][t] = (notTake | take);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;

        if (sum % 2 != 0) return false;  // If total sum is odd, can't partition equally

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return fn(nums.size() - 1, target, nums, dp);
    }
};
