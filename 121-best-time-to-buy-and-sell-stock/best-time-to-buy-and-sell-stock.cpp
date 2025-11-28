class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxP = 0;

        for(int i = 0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            int profit = prices[i] - mini;
            maxP = max(maxP,profit);
        }return maxP;

    }
};