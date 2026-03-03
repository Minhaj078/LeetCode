class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0, prdct = 1,n = nums.size();
        if(k <= 1)return 0;
        while(j < n){
            prdct *= nums[j];
            while(prdct >= k){
                prdct /= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
    return cnt;
    }
};