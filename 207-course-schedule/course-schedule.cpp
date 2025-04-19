class Solution {
public:

    bool detect(int node,vector<int>&path,vector<vector<int>>& adj,vector<int>&vis){
        vis[node] = 1;
        path[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(detect(it,path,adj,vis))return true;
            }
            else if(path[it])return true;
        }
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);  // it[1] → it[0]
        }
        vector<int>path(numCourses,0);
        vector<int>vis(numCourses,0);

        for(int i = 0;i<numCourses;i++){
            if(!vis[i]) if(detect(i,path,adj,vis))return false; //mtlb ki hn bhai cycle hai tm course ni kr paoge khtm ..
        }
        return true;
    }
};