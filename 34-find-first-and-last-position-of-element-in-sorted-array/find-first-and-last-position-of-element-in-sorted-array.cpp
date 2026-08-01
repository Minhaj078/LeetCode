class Solution {
public:

    int ub(vector<int>&arr, int target){
        int low = 0, high = arr.size() - 1, ans = arr.size();

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int lb(vector<int>&arr, int target){
        int low = 0, high = arr.size() - 1, ans = arr.size();

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

    int first = lb(nums, target);

    // target not found
    if(first == nums.size() || nums[first] != target)
        return {-1, -1};

    int last = ub(nums, target) - 1;

    return {first, last};
}
};
