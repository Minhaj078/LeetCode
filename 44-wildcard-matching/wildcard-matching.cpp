class Solution {
public:

    bool fn(int i, int j, string &s, string &p, vector<vector<int >> &dp){
        if (i < 0 && j < 0) return true;

        // 2. Pattern finished but string not
        if (j < 0) return false;

        // 3. String finished but pattern remains
        if (i < 0) {
            // remaining pattern must be all '*'
            for (int k = 0; k <= j; k++)
                if (p[k] != '*') return false;
            return true;
        }

        // MEMO ------------------------------------------
        if (dp[i][j] != -1) return dp[i][j];

        // MATCHING LOGIC --------------------------------

        // Case 1 → exact char match OR '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = fn(i - 1, j - 1, s, p, dp);

        // Case 2 → '*' can take 2 choices:
        if (p[j] == '*') {
            return dp[i][j] = 
                   fn(i - 1, j, s, p, dp)      // '*' matches a character
                || fn(i, j - 1, s, p, dp);    // '*' matches empty
        }

        // Case 3 → No match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int a = s.size();
        int b = p.size();
        vector<vector<int >> dp(a + 1,vector<int>(b + 1,-1));
        return fn(a-1, b-1, s, p, dp);
    }
};