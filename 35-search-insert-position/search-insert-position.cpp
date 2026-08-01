class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size(), left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left+(right - left )/2;

            if(nums[mid] >= target){
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) left = mid + 1;
        }
        return ans;
    }
};