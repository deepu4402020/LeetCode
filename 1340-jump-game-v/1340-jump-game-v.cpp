class Solution {
private:

    int f(int i, vector<int>&v, int d, vector<int>&dp, int n){

        if(dp[i] != -1) return dp[i];
        int res = 1;

        // Left
        for(int j = i-1; j >= max(0, i-d); j--){
            if(v[j] >= v[i]) break;
            res = max(res, 1 + f(j, v, d, dp, n));
        }

        // Right
        for(int j = i+1; j <= min(n-1, i+d); j++){
            if(v[j] >= v[i]) break;
            res = max(res, 1 + f(j, v, d, dp, n));
        }

        return dp[i] = res;
    }

public:

    int maxJumps(vector<int>&v, int d){

        int n = v.size();
        int ans = 1;
        vector<int>dp(n, -1);

        for(int i = 0; i < n; i++){
            ans = max(ans, f(i, v, d, dp, n));
        }

        return ans;
    }
};