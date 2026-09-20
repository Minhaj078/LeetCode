class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        unordered_map<int,int>mp;

        long long sum = 0, maxi = 0;
        for(int r = 0;r<nums.size();r++){
            sum += nums[r];
            mp[nums[r]]++;

            while(r - left + 1 > k){ // check for out of range
                sum -= nums[left];
                mp[nums[left]]--;

                if(mp[nums[left]] == 0)mp.erase(nums[left]);
                left++;
            }
            if(r - left + 1 == k && mp.size() == k)maxi = max(maxi, sum);
        }return maxi;
    }
};