class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt=0;
        bool check=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(cnt<k && i!=0 && check!=false)return false;
                cnt=0;
                check=true;
            }else{
                cnt++;
            }
        }
        return true;
    }
};