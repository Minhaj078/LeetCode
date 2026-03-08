class Solution {
public:
    string f(int n,string bin,unordered_set<string> mp){
        if(bin.length()==n){
            if(mp.find(bin)==mp.end()){
                return bin;
            }else{
                return "";
            }
        }
        string res =f(n,bin + '0', mp);
        if (!res.empty()) return res;
        return f(n,bin + '1', mp);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> mp(nums.begin(),nums.end());
        string bin;
        return f(nums.size(),bin,mp);
    }
};