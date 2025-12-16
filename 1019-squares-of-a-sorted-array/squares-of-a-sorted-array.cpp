class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;

        int pos = n-1;
        vector<int>ans(n);

        while(right >= left){
            if(abs(nums[left]) > abs(nums[right])){
                ans[pos] = nums[left] * nums[left];
                left++;
                pos--;
            }
            else{
                ans[pos] = nums[right] * nums[right];
                right--;
                pos--;
            }
        }
        return ans;
    }
};