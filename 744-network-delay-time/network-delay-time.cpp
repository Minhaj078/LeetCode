class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1]; // (destination, weight)

        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        set<pair<int,int>> st;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        st.insert({0, k});

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto &[adjNode, edgewt] : adj[node]){
                if(dist[node] + edgewt < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dist[node] + edgewt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1; // unreachable node
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
