class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > nums[(i+1) % nums.size()])cnt++; //we use modulo to compare the last one element with first one element
        }return cnt <=1;
    }
};