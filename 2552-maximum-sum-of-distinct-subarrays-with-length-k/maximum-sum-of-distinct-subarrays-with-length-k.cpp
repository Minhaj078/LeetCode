class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, maxi = 0;

        int left = 0;
        //for checking all the elements are unique!
        unordered_map<int,int>mp;
        for(int r = 0;r<nums.size();r++){
            ans += nums[r];
            mp[nums[r]]++;

            while(r - left + 1 > k){
                ans -= nums[left];
                mp[nums[left]]--;

                if(mp[nums[left]] == 0)mp.erase(nums[left]);
                left++;
            }

            if(r - left + 1 == k && mp.size() == k){
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
};