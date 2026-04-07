class Solution {
    private:

        int n;
    int memo[50001][2];

   int solve(vector<int>& prices, int i, int holding, int fee) {
    if (i >= n) return 0;

    if (memo[i][holding] != -1) return memo[i][holding];

    int profit = 0;

    if (holding == 0) {
        int skip = solve(prices, i + 1, 0, fee);
        int buy  = -prices[i] - fee + solve(prices, i + 1, 1, fee);

        profit = max(skip, buy);
    } 
    else {
        int hold = solve(prices, i + 1, 1, fee);
        int sell = prices[i] + solve(prices, i + 1, 0, fee);  

        profit = max(hold, sell);
    }

    return memo[i][holding] = profit;
}


public:
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(memo, -1, sizeof(memo));
        return solve(prices, 0, 0 , fee);
    }
};