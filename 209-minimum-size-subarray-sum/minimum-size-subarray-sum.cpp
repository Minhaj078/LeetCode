class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX, left = 0, sum = 0;
        for(int r = 0;r<nums.size();r++){
            sum += nums[r];
            while(sum >= target){
                mini = min(mini, r - left + 1);
                sum -= nums[left];
                left++;
            }
        }return mini == INT_MAX ? 0:mini;
    }
};