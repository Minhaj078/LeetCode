class Solution {
public:

    int fn(int i,int a,vector<int>&coins, vector<vector<int>>&dp){
        if(i == 0){
            return (a % coins[0] == 0) ? 1 : 0;
        }

        if(dp[i][a] != -1) return dp[i][a];

        int notTake = fn(i-1, a, coins, dp);
        int take = 0;
        if(a - coins[i] >= 0)
            take = fn(i, a - coins[i], coins, dp);

        return dp[i][a] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return fn(coins.size()-1, amount, coins, dp);
    }
};
