class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int sum = numBottles;
        // if(numBottles < numExchange)return sum;

        while(numBottles >= numExchange){
            int nB = numBottles/numExchange;
            sum+= nB;
            numBottles = nB + (numBottles%numExchange);

        }
        return sum;
    }
};