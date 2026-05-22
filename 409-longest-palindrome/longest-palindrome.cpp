class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_map<char,int>mp;

        bool oddFlag = false;

        for(char it : s){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second % 2 == 0){
                len += it.second;
            }else{
                len += it.second - 1;
                oddFlag = true;
            }
        }
        if(oddFlag)len++;
        return len;
    }
};