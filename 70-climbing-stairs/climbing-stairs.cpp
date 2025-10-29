class Solution {
public:

    int fn (int n, vector<int>&dp){
        if(n == 0)return 1;
        if(n < 0)return 0;

        if(dp[n]!= -1)return dp[n];

        int step1 = fn(n-1, dp);
        int step2 = fn(n-2, dp);
        return dp[n] =  step1 + step2;

    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(n, dp);
    }
};