class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;

        for(char x : s) freq[x]++;
        for(char x : t) freq[x]--;

        for(auto p : freq){
            if(p.second != 0) return false;
        }

        return true;
    }
};