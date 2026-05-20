class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0,maxi = INT_MIN;

        unordered_map<char, int>mp;

        while(r < s.size()){
            mp[s[r]]++;

            while(mp[s[r]] > 1){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};