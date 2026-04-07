class Solution {
private:
    int n;
    int memo[5001][2];
    int solve(vector<int>& prices, int i, int holding) {
        if (i >= n) {
            return 0;
        }
        if (memo[i][holding] == -1) {
            int buy = 0, dontbuy = 0;
            // decide to buy
            if (!holding) {
                buy = -prices[i] + solve(prices, i + 1, 1);
                dontbuy = solve(prices, i + 1, 0);
                return memo[i][holding] = max(buy, dontbuy);
            }

            else {
                int sell = prices[i] + solve(prices, i + 2, 0);

                int hold = solve(prices, i + 1, 1);

                return memo[i][holding] = max(sell, hold);
            }
        }
        return memo[i][holding];
    }

public:
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        n = prices.size();
        return solve(prices, 0, 0);
    }
};