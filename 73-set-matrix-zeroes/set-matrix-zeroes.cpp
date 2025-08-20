class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool fr = false, fc = false;

        // check first row & first column
        for (int j = 0; j < m; j++) if (matrix[0][j] == 0) fr = true;
        for (int i = 0; i < n; i++) if (matrix[i][0] == 0) fc = true;

        // mark zeros in first row & col
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        // update cells
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // update first row & column if needed
        if (fr) for (int j = 0; j < m; j++) matrix[0][j] = 0;
        if (fc) for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};
