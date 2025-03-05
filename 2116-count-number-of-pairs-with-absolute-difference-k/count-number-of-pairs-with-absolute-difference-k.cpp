class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // unordered_map<int, int> freq;
        // int count = 0;
        
        // // Loop through each element in the vector
        // for (int num : nums) {
        //     // Agar (num - k) pehle se exist karta hai, to un pairs ko add karo
        //     if (freq.find(num - k) != freq.end()) {
        //         count += freq[num - k];
        //     }
        //     // Agar (num + k) pehle se exist karta hai, to un pairs ko add karo
        //     if (freq.find(num + k) != freq.end()) {
        //         count += freq[num + k];
        //     }
            
        //     // Update frequency of current element
        //     freq[num]++;
        // }
        // return count;

    int freq[101] = {0};  // Since 1 <= nums[i] <= 100
    int count = 0;

    // Step 1: Count frequency of each number (O(N))
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Count valid pairs (O(N))
    for (int i = 1; i <= 100; i++) {
        if (i + k <= 100) {
            count += freq[i] * freq[i + k];
        }
    }

    return count;
    }
};
