class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int nz = 0, maxLen = 0, left = 0;

        for(int right = 0; right<nums.size(); right++){
            if(nums[right] == 0)nz++;
            while(nz > k){
                if(nums[left] == 0){
                    nz--;
                }
                left++;
            }
                maxLen = max(maxLen, right- left + 1); 
        }           
        return maxLen;
    }
};