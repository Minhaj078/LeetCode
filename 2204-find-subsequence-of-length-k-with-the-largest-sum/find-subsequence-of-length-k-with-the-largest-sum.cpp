class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>copy = nums;
        vector<int>ans;
        int n = nums.size();
        sort(copy.begin(),copy.end());

        unordered_map<int,int>mp;

        for(int i =0;i<k;i++){
            mp[copy[n-1-i]]++;
        }

        for(int i = 0;i<n;i++){
            if(mp[nums[i]] > 0){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
            }

            if(ans.size() == k){
                break;
            }
        }
    return ans;
    }
};