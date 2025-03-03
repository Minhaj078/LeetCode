class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> mpp; // Use unordered_map for O(1) average time complexity
        
        for (int num : nums) {
            if (++mpp[num] > 1) return true; // If count becomes > 1, return early
        }

        return false;
    }
};