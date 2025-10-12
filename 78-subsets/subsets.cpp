class Solution {
public:

    void fn(int i, vector<int>&ds, vector<vector<int>> &ans, vector<int> nums){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        fn(i+1, ds, ans, nums);
        ds.pop_back();
        fn(i+1, ds, ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        fn(0, ds, ans, nums);
        return ans;
    }
};