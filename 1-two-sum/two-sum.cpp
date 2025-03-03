class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // Hash map to store (num, index)
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in the hash map
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // Return indices of complement and current element
        }
        
        // Store the current number and its index in the map
        mp[nums[i]] = i;
    }
    
    return {}; // This case won't happen as per the problem statement
}
};