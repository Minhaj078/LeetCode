class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDel = arr[0];
        int oneDel = 0;
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++) {

            int temp = noDel;

            noDel = max(arr[i], noDel + arr[i]);

            oneDel = max(temp, oneDel + arr[i]);

            ans = max(ans, max(noDel, oneDel));
        }

        return ans;
    }
};