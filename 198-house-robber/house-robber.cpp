class Solution {
public:

    int fn(int n, vector<int>nums,vector<int>&dp){
        if(n == 0)return nums[n];
        if(n < 0)return 0;

        if(dp[n] != -1)return dp[n];

        int notPick = fn(n-1,nums,dp);
        int pick = nums[n]+fn(n-2,nums,dp);

        return dp[n] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() + 1,-1);
        return fn(nums.size()-1,nums,dp);
    }
};