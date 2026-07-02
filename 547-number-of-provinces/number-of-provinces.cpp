class Solution {
public:

    void dfs(int num, vector<vector<int>>& adj, vector<int>& vis){
        vis[num] = 1;
        int n = adj.size();
        for(auto it : adj[num]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};