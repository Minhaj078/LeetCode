class Solution {
public:


    int fn(int i, int j, vector<vector<int>>&dp, vector<vector<int>>& arr,int n){
        if(i == n-1)return arr[n-1][j];

        if(dp[i][j] != -1)return dp[i][j];

        int d = arr[i][j] + fn(i+1,j,dp,arr,n);
        int dg = arr[i][j] + fn(i+1,j+1,dp,arr,n);

        return dp[i][j] = min(d,dg);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //This memoization will give us TLE;
        // vector<vector<int >>dp(n,vector<int>(n,-1));
        // return fn(0,0,dp,triangle,n);

        vector<vector<int >>dp(n,vector<int>(n,0));

        for(int j = 0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }

        return dp[0][0];

    }
};
