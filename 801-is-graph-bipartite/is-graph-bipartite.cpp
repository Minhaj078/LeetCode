//bfs

// class Solution {
// public:

//    bool check(int start,int v,vector<vector<int>>& graph,int color[]){
//         queue<int>q;
//         q.push(start);
//         color[start] = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();

//             for(auto it:graph[node]){
//                 if(color[it] == -1){
//                     color[it] = !color[node];
//                     q.push(it);
//                 }
//                 else if(color[it] == color[node])return false;
//             }
//         }return true;
//     }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int v = graph.size();
//         int color[v];
//         for(int i = 0;i<v;i++){
//             color[i] = -1;
//         }
//         for(int i = 0;i<v;i++){
//             if(color[i] == -1){
//                 if(check(i,v,graph,color) == false)return false;
//             }
//         }
//         return true;
//     }  
// };

//dfs
class Solution {
public:

    bool check(int node, vector<vector<int>>& graph, int color[]) {
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                color[it] = !color[node];
                if (!check(it, graph, color)) return false;
            }
            else if (color[it] == color[node]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        int color[v];
        for (int i = 0; i < v; i++) {
            color[i] = -1;
        }

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                color[i] = 0; // Set initial color before DFS
                if (!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};
