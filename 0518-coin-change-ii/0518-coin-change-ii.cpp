class Solution {
public:

    int dp[301][10001];
    
    int solve(vector<int>& coins, int i, int rem) {
        if(i < 0){
            if(rem == 0) {

                 return 1;
            }
            return 0;
        }

        if(dp[i][rem] != -1) return dp[i][rem];
        

        int sel = 0;
        if(coins[i] <= rem){
            sel =  solve(coins, i, rem - coins[i]);
        }
        int skip = solve(coins, i-1, rem);

        return dp[i][rem] = (sel+ skip); 
    }
    int change(int amount, vector<int>& coins) {
         memset(dp, -1, sizeof(dp)); 

        int n = coins.size();
        
        int ans = solve(coins, n-1, amount);
        return ans;
    }
};