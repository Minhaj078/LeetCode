class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0, l = 0, r = 0, maxLen = 0, nz = 0;

        while(r < nums.size()){
            if(nums[r] == 0)nz++;

            while(nz > k){
                if(nums[l] == 0)nz--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }return maxLen;
    }
};