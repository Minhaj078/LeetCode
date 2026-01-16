class Solution {
public:
    int ans = 0, mod = 1e9+7;
    unordered_map<int,bool> umap;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(m);v.push_back(n);
        func(h);func(v);
        return ans==0?-1:(1LL*ans*ans)%mod;
    }
    void func(vector<int>& temp)
    {  
        bool check = umap.size();
        temp.push_back(1);
        sort(temp.begin(),temp.end());
        for(int i = 0; i < temp.size();i++)
            for(int j = i+1; j < temp.size(); j++)
                if((check || !(umap[temp[j]-temp[i]]=1)) && umap[temp[j]-temp[i]])
                    ans = max(ans,temp[j]-temp[i]);
    }
};