class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1; // 1 means currently in recursion stack

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (!dfs(it, vis, adj, st)) return false;
            }
            else if (vis[it] == 1) {
                // Cycle found
                return false;
            }
        }

        vis[node] = 2; // 2 means processed
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, vis, adj, st)) {
                    return {}; // cycle found, not possible to finish all
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
