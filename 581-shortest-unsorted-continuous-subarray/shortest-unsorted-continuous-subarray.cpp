class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();

        int left = 0, right = n-1;

        while(left < n && nums[left] == temp[left])left++;
        while(right > 0 && nums[right] == temp[right])right--;
        if(nums == temp){
            return 0;
        }
        return (right - left + 1);
    }
};