class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];   // final answer
        int currSum = nums[0];  // running sum

        for (int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]); // continue ya restart
            maxSum = max(maxSum, currSum);             // update max
        }

        return maxSum;
    }
};
