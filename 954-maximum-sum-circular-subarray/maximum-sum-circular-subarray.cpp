class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], MaxSum = nums[0], Minsum = nums[0], totalSum = nums[0];

        for(int i = 1;i<nums.size();i++){

            //kadane Algo for maxsum

            currMax = max(nums[i], currMax + nums[i]);
            MaxSum = max(MaxSum , currMax);

            //kadane Algo for minSum

            currMin = min(nums[i], currMin + nums[i]);
            Minsum = min(Minsum , currMin);

            totalSum += nums[i];
        }
        if(MaxSum < 0)return MaxSum;
        return max(MaxSum, totalSum - Minsum);
    }
};