class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int buy = -prices[0], sell = 0, cool = 0;
        for (int i = 1; i < prices.size(); i++) {
            int newBuy = max(buy, cool - prices[i]);
            int newSell = max(sell, buy + prices[i]);
            int newCool = max(cool, sell);
            buy = newBuy; sell = newSell; cool = newCool;
        }
        return max(sell, cool);
    }
};