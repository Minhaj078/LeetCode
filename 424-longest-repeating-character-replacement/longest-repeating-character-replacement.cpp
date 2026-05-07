class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l = 0, maxLen = 0, cnt = 0;
        
        for(int r = 0;r<s.size();r++){
            mp[s[r]]++;
            cnt = max(cnt, mp[s[r]]);
            while((r - l + 1 ) - cnt > k){
                mp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};