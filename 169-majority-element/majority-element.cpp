class Solution {
public:
        int majorityElement(vector<int>& nums) {
        map<int, int> mp; // Declare the map correctly

        // Count occurrences of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Find the element with the highest frequency using max function
        int maxFreq = 0, majorityElem = 0;
        for (auto it : mp) {
            if (it.second > maxFreq) {
                maxFreq = max(maxFreq, it.second);  // Update max frequency
                majorityElem = it.first; // Store corresponding element
            }
        }

        return majorityElem;
    }
};