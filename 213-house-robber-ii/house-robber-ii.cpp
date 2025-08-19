class Solution {
public:
    int fn(int n, vector<int>nums,vector<int>&dp){
        if(n == 0)return nums[n];
        if(n < 0)return 0;

        if(dp[n] != -1)return dp[n];

        int pick = nums[n]+fn(n-2,nums,dp);
        int notPick = fn(n-1,nums,dp);

        return dp[n] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();

        if(n == 1)return nums[0];

        for(int i = 0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }

        vector<int>dp(n+1,-1);
        vector<int>dp1(n+1,-1);

        return max(fn(temp1.size()-1,temp1,dp),fn(temp2.size()-1,temp2,dp1));
    }
};