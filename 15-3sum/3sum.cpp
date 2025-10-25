class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i = 0;i<n;i++){
            unordered_set<int>seen;
            if(i > 0 && nums[i] == nums[i-1])continue; //and this for ensuring no duplicates numbr.

            for(int j = i+1;j<n;j++){
                
                int third = -(nums[i] + nums[j]);
                if(seen.count(third))
                {

                ans.push_back({nums[i],third,nums[j]});

                while(j+1 < n && nums[j] == nums[j+1])j++; //we do this for ensuring no duplicates of triplets.

                }
                seen.insert(nums[j]);
            }
            
        }
        return ans;
    }
};