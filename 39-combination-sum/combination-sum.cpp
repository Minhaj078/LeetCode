class Solution {
public:

    void CSum(int indx,int target,vector<int>arr,vector<vector<int>>&ans,vector<int>&ds){
        if(indx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        //pick the element
        if(arr[indx] <= target){
            ds.push_back(arr[indx]);
            CSum(indx,target - arr[indx], arr,ans,ds);
            ds.pop_back();
        }
        //not pick
        CSum(indx+1,target,arr,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        CSum(0,target,candidates,ans,ds);
        return ans;

    }      
};