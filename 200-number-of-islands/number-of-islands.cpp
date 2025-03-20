class Solution {
public:

    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delrow [] = {-1,0,1,0};
            int delcol [] = {0,1,0,-1};
            for(int i = 0;i<4;i++)
            {
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];

                    if(nrow >= 0 && nrow< n && ncol >=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }return cnt;
    }
};