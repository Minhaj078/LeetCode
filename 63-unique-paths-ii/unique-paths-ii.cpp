class Solution {
public:

    int fn(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >=0 && j >=0 && grid[i][j] == 1)return 0; //obstacle found
        if(i == 0 && j == 0) return 1; //sirf starting ko hi return kro 1
        if(i<0 || j <0)return 0; //out of the boundry

        if(dp[i][j] != -1)return dp[i][j];

        int left = fn(i,j-1,grid,dp);
        int top = fn(i-1,j,grid,dp);

        return dp[i][j] = left + top;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,obstacleGrid,dp);
    }
};