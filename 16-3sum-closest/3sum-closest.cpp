class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0;i<n-2;i++){
            int left = i+1, right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(sum - target) < abs(closest - target)){
                    closest = sum;
                }
                else if(target > sum){ //array sorted hai -4 -1 1 2 target=1 target > sum then aage check kro
                    left++;
                }
                else if(target < sum){ //ya phir piche check kro
                    right--;
                }
                else{
                    return sum;
                }
            }
        }
        return closest;
    }
};