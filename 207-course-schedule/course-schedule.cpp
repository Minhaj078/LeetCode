class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        return cnt == numCourses;
    }
};