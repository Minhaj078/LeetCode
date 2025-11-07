class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        if (v.size() < 3)
            return v[0]; // largest
        return v[2];     // 3rd largest
    }
};
