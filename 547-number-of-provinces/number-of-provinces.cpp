class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjLs) {
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjLs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);  // Correct adjacency list declaration

        // Convert matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // Avoid duplicate edges
                if (isConnected[i][j] == 1) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n, 0);  // Correct visit array initialization

        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adjLs);
                cnt++;
            }
        }

        return cnt;
    }
};
