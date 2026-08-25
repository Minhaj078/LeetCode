class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1;
        vector<int>ans(n);

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            if(abs(nums[left]) < abs(nums[right])){
                ans[pos] = nums[right] * nums[right];
                pos--;
                right--; 
            }
            else{
                ans[pos] = nums[left] * nums[left];
                left++;
                pos--;
            }
        }return ans;
    }
};