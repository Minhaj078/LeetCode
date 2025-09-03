class Solution {
public:

    int fn(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j < 0 || j >= matrix[0].size())return 1e9;

        if(i == 0)return matrix[0][j];

        if(dp[i][j] != -1)return dp[i][j];

        int leftUp = matrix[i][j] + fn(i-1,j-1,matrix,dp);
        int up = matrix[i][j] + fn(i-1,j,matrix,dp);
        int rightUp = matrix[i][j] + fn(i-1, j+1, matrix,dp);

        return dp[i][j] = min(leftUp,min(up,rightUp));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // int mini = INT_MAX;
        // for(int j = 0;j<n;j++){
        //     mini = min(mini,fn(n-1,j,matrix,dp));
        // }
        // return mini;



        // First row as it is
        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        // Fill DP
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i-1][j];

                int leftDown = INT_MAX;
                if (j > 0) leftDown = matrix[i][j] + dp[i-1][j-1];

                int rightDown = INT_MAX;
                if (j < n-1) rightDown = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(down, min(leftDown, rightDown));
            }
        }

        // Answer is min of last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};
