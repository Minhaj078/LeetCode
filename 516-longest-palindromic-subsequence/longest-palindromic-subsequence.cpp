class Solution {
public:

    int fn(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + fn(i-1,j-1, s,t,dp);

        else{
            return dp[i][j] = max(fn(i-1,j,s,t,dp),fn(i,j-1,s,t,dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>>dp(s.size() + 1,vector<int>(s.size() + 1,-1));
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        int m = t.size();
        return fn(n-1,m-1,s,t,dp);
    }
};