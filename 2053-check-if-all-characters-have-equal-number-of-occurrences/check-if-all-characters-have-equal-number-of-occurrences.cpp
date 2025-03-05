class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int>mpp;
        for(int i= 0;i<s.length();i++){
            mpp[s[i]]++;
        }
        int freq = mpp.begin()->second;
        for(auto it:mpp){
            if(it.second != freq)return false;
        }return true;
    }
};