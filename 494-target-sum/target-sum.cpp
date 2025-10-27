class Solution {
public:
    int fn(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int notTake = fn(i - 1, sum, nums, dp);
        int take = 0;
        if (nums[i] <= sum)
            take = fn(i - 1, sum - nums[i], nums, dp);

        return dp[i][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is impossible (odd or negative subset sum)
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0)
            return 0;

        int newTarget = (totalSum + target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(newTarget + 1, -1));

        return fn(nums.size() - 1, newTarget, nums, dp);
    }
};
