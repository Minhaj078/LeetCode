class Solution {
public:

    int fn(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&arr){

        if(i >= 0 && j >= 0 && arr[i][j] == 1)return 0;

        if(i < 0 || j < 0)return 0;

        if(i == 0 && j == 0)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int left = fn(i, j-1, dp, arr);
        int up = fn(i-1, j, dp, arr);

        return dp[i][j] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return fn(n-1,m-1,dp,obstacleGrid);
    }
};