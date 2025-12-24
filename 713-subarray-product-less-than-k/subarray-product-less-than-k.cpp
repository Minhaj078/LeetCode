class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0,j = 0,product = 1,cnt = 0;
        if(k <= 1)return 0;
        while(j < nums.size()){
            product *= nums[j];
            while(product >= k){
                product /= nums[i];
                i++;
            } 
            cnt += (j - i + 1);
            j++;
        }
            return cnt;
    }

};