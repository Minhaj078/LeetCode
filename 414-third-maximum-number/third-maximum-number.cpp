class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // store unique elements (sorted ascending)
        set<int> s(nums.begin(), nums.end());
        
        // if less than 3 unique numbers, return max
        if (s.size() < 3)
            return *s.rbegin(); // largest element
        
        // otherwise, return third maximum
        auto it = s.rbegin(); // reverse iterator (largest → smallest)
        advance(it, 2); // move to 3rd largest
        return *it;
    }
};
