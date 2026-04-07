class Solution {
private:
    int n;
    int memo[5001][2];

    int solve(vector<int>& prices, int i, int holding) {
        if (i >= n) return 0;

        if (memo[i][holding] != -1) return memo[i][holding];

        int profit = 0;


        if (holding == 0) {
            int skip = solve(prices, i + 1, 0);
            int buy  = -prices[i] + solve(prices, i + 1, 1);

            profit = max(skip, buy);
        }

        else {
            int hold = solve(prices, i + 1, 1);
            int sell = prices[i] + solve(prices, i + 2, 0);

            profit = max(hold, sell);
        }

        return memo[i][holding] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(memo, -1, sizeof(memo));
        return solve(prices, 0, 0);
    }
};