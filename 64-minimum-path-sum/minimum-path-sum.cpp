class Solution {
public:

    long long fn(int i, int j, vector<vector<long long>> &dp, vector<vector<int>> &grid){
        if(i == 0 && j == 0)return grid[i][j];

        if(i < 0 || j < 0)return INT_MAX;

        if(dp[i][j] != -1)return dp[i][j];

        long long left = grid[i][j] + fn(i,j-1, dp, grid);
        long long up = grid[i][j] + fn(i-1,j, dp, grid);
        
        return dp[i][j] = min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        return (int) fn(n-1, m-1, dp, grid);
    }
};