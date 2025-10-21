class Solution {
public:
    int fn(int i, int a, vector<vector<int>>& dp, vector<int>& coins) {
        // base case
        if (i == 0) {
            if (a % coins[0] == 0) return a / coins[0];
            return 1e9;
        }

        if (dp[i][a] != -1) return dp[i][a];

        int notTake = fn(i - 1, a, dp, coins);
        int take = 1e9;

        if (coins[i] <= a) {
            take = 1 + fn(i, a - coins[i], dp, coins);
        }

        return dp[i][a] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = fn(n - 1, amount, dp, coins);
        return (ans != 1e9) ? ans : -1;
    }
};
