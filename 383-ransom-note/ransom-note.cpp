class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // bool flag = false;

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(char it : ransomNote){
            mp1[it]++;
        }
        for(char it : magazine){
            mp2[it]++;
        }

        for(auto it : mp1){
            if(it.second > mp2[it.first])return false;
        }return true;
    }
};