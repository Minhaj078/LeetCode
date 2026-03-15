class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minL = INT_MAX;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(sum >= target){
                minL = min(minL, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if(minL == INT_MAX) return 0;
        return minL;
    }
};