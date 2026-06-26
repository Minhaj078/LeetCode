class Solution {
public:

    void dfs(int row, int col, int drow[], int dcol[],vector<vector<int>>& image, vector<vector<int>>& copy, int inicolor, int color){
        copy[row][col] = color;
        int r = image.size();
        int c = image[0].size();

        for(int i = 0;i < 4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >=0 && nrow < r && ncol >=0 && ncol < c && image[nrow][ncol] == inicolor && copy[nrow][ncol] != color){
                dfs(nrow,ncol, drow,dcol, image, copy, inicolor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>copy = image;

        int inicolor = image[sr][sc];

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        dfs(sr,sc,drow,dcol,image,copy,inicolor,color);
        return copy;
    }
};