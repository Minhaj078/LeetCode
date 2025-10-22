class Solution {
public:

    int fn(int n, int a, vector<int>&coins, vector<vector<int>> &dp){

        if(n == 0){
           return (a % coins[0] == 0) ? a/coins[0] : 1e9;
        }

        if(dp[n][a] != -1)return dp[n][a];

        int notTake = 0 + fn(n-1, a, coins, dp);
        int take = 1e9;

        if(a >= coins[n]) take = 1 + fn(n, a - coins[n], coins, dp);

        return dp[n][a] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1, -1));
        int ans = fn(coins.size()-1, amount, coins, dp);
        return (ans == 1e9) ? -1 : ans;

    }
};