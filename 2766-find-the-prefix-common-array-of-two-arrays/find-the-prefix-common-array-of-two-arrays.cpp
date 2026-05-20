class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;

        unordered_map<int,int>mp;

        for(int i = 0;i<A.size();i++){
            int cnt = 0;
            mp[A[i]]++;
            mp[B[i]]++;
            for(auto it:mp){
                if(it.second > 1){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }return ans;
    }
};
