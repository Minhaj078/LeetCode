class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());

        while(left < right && nums[left] == temp[left])left++;
        while(right >= 0 && nums[right] == temp[right])right--;
        if(left >= right)return 0;

        return (right - left + 1);
    }
};