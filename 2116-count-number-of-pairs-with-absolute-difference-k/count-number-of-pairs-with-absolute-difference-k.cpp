class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        
        // Loop through each element in the vector
        for (int num : nums) {
            // Agar (num - k) pehle se exist karta hai, to un pairs ko add karo
            if (freq.find(num - k) != freq.end()) {
                count += freq[num - k];
            }
            // Agar (num + k) pehle se exist karta hai, to un pairs ko add karo
            if (freq.find(num + k) != freq.end()) {
                count += freq[num + k];
            }
            
            // Update frequency of current element
            freq[num]++;
        }
        return count;
    }
};
