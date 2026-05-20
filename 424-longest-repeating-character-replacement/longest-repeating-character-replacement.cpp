class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxi = INT_MIN, maxFreq = 0;
        unordered_map<char, int>mp;

        while(r < s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while((r - l + 1 ) - maxFreq > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }return maxi;
    }
};