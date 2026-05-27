class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int oneDel = 0,noDel = arr[0], ans = arr[0];

        for(int i = 1; i<arr.size();i++){

            int temp = noDel;
            noDel = max(arr[i], arr[i] + noDel); //normal Kadane

            oneDel = max(temp, arr[i] + oneDel);

            ans = max(ans,max(noDel, oneDel));
            
        }return ans;
    }
};