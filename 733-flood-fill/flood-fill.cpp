class Solution {
public:

    void dfs(int row,int col,int delRow[],int delCol[],vector<vector<int>>& image,int inicolor,vector<vector<int>>& copy,int color){
        copy[row][col] = color;

        int r = image.size();
        int c = image[0].size();

        for(int i = 0;i<4;i++){
            
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >=0 && nrow<r && ncol >= 0 && ncol < c && image[nrow][ncol] == inicolor && copy[nrow][ncol] != color){
                dfs(nrow,ncol,delRow,delCol,image,inicolor,copy,color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>copy = image;
        int inicolor = image[sr][sc];
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        dfs(sr,sc,delRow,delCol,image,inicolor,copy,color);
        return copy;
    }
};