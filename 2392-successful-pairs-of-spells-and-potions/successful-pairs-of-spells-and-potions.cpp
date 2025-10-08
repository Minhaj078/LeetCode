class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort the potions
        sort(potions.begin(), potions.end());
        vector<int> ans;

        // Step 2: For each spell, find how many potions work
        for (int i = 0; i < spells.size(); i++) {
            // Step 3: Minimum potion strength needed
            long long minPotion = (success + spells[i] - 1) / spells[i];

            // Step 4: Find first potion >= minPotion using binary search
            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            // Step 5: Count potions from idx to end
            ans.push_back(potions.size() - idx);
        }

        return ans;
    }
};