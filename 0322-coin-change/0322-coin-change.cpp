class Solution {
private:
    int n;
    int dp[13][10001];
    
    int solve(vector<int>& coins, int i, int rem) {
        if(i < 0){
            if(rem == 0) return 0;
            return 1e8;
        }

        if(dp[i][rem] != -1) return dp[i][rem];
        

        int sel = 1e8;
        if(coins[i] <= rem){
            sel = 1 + solve(coins, i, rem - coins[i]);
        }
        int skip = solve(coins, i-1, rem);

        return dp[i][rem] = min(sel, skip); 
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp)); 
        sort(coins.begin(), coins.end());
        n = coins.size();
        
        int ans = solve(coins, n-1, amount);
        return (ans >= 1e8) ? -1 : ans;
    }
};