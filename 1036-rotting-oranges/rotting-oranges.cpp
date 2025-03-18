class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntfresh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2; // visited the rotten apple in visisted array
                }else{
                    vis[i][j] = 0; // rather there will be empty space or fresh apple
                }
                if(grid[i][j] == 1)cntfresh++; //got that fresh orange
            }
        }

        int tm = 0,rotted = 0;
        //for calculating my neighbours make an array for up down left right;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(t,tm);
            q.pop();

            for(int i = 0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
                rotted++;
            }
            }
        }return cntfresh == rotted ? tm:-1;
    }
};