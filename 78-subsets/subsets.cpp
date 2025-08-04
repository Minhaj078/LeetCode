class Solution {
public: 

    void findSubset(int indx,vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
        if(indx == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[indx]);
        findSubset(indx+1,nums,ds,ans);
        ds.pop_back();
        findSubset(indx+1,nums,ds,ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        findSubset(0,nums,ds,ans);
        return ans;
    }
};