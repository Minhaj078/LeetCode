class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        int maxP = INT_MIN;

        for(int i = 0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            profit = prices[i] - mini;
            maxP = max(maxP, profit);
        }
        return maxP;
    }
};