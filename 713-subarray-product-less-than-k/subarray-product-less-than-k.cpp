class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0, pdt = 1;
        if (k <= 1) return 0;
        while(r < nums.size()){
            pdt *= nums[r];
            while(pdt >= k){
                pdt /= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};