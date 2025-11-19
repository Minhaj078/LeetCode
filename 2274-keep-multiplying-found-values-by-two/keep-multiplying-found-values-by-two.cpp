class Solution {
public:

    int fn(vector<int>& nums,int &original){
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == original)return (nums[i] * 2);
        }
        return original;    
    }

    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        for(int i = 0;i<nums.size();i++){
            ans = fn(nums,original);
            original = ans;
        }return ans;
    }
};