class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        // Step 1: Create reverse graph and compute indegree
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u); // reverse the edge
                indegree[u]++;            // original node u had outgoing edge
            }
        }

        // Step 2: Topological sort using queue (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i); // terminal or safe nodes
            }
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Sort the safe nodes as per question
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
