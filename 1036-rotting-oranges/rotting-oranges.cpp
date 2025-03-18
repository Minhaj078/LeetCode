class Solution {
public:
    typedef pair<int,int>r;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<r>q;
        //vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntfresh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.emplace(i,j);
                    //vis[i][j] = 2; // visited the rotten apple in visisted array
                }else if(grid[i][j] == 1)cntfresh++; //got that fresh orange
            }
        }
        if(cntfresh==0){
            return 0;
        }
        int time = 0;
        //for calculating my neighbours make an array for up down left right;
        constexpr int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int p=q.size();
            while(p--){
            r node=q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
                for(auto& [dx,dy]:dirs){
                    int nrow=i+dx;
                    int ncol=j+dy;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1){
                grid[nrow][ncol] = 2;
                q.emplace(nrow,ncol);
                cntfresh--;
            }
            }
            }
            time++;
        }
        return cntfresh == 0?time-1:-1;
    }
};