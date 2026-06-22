class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        int Srow = 0, Scol = 0, Erow = row - 1, Ecol = col - 1;

        int total = row * col, cnt = 0;
        vector<int>ans;
        while(cnt < total){
            
            //Printing Starting Row
            for(int index = Scol; index <= Ecol && cnt < total; index++){
                ans.push_back(matrix[Srow][index]);
                cnt++;
            }
            Srow++;

            //Printing Ending Col
            for(int index = Srow; index <= Erow && cnt < total; index++){
                ans.push_back(matrix[index][Ecol]);
                cnt++;
            }
            Ecol--;

            //Printing Ending row
            for(int index = Ecol; index >= Scol && cnt < total; index--){
                ans.push_back(matrix[Erow][index]);
                cnt++;
            }
            Erow--;

            //Printing Starting row
            for(int index = Erow; index >= Srow && cnt < total; index--){
                ans.push_back(matrix[index][Scol]);
                cnt++;
            }
            Scol++;
        }
        return ans;
    }
};