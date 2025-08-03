class Solution {
public:

    void csum(int indx,int target, vector<int>arr,vector<vector<int>>&ans,vector<int>ds){
        if(indx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        //pick
        if(arr[indx] <= target){
            ds.push_back(arr[indx]);
            csum(indx,target - arr[indx],arr,ans,ds);
            ds.pop_back();
        }

        //not pick
        csum(indx+1,target,arr,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> ans;
        csum(0,target, candidates,ans,ds);
        return ans;
    }
};