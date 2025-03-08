class Solution {
public:
       int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int minOps = k;  // Max possible value since we may need to change all k blocks
        int whiteCount = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount++;
            }
        }

        minOps = whiteCount;  // Initialize minOps with the first window's count

        // Slide the window
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') whiteCount++;    // Add new character in the window
            if (blocks[i - k] == 'W') whiteCount--; // Remove old character from the window
            
            minOps = min(minOps, whiteCount); // Track minimum operations
        }

        return minOps;
    }
};