class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> points(mx + 1, 0);

        for(int x : nums)
            points[x] += x;

        vector<int> dp(mx + 1, 0);

        dp[0] = 0;
        dp[1] = points[1];

        for(int i = 2; i <= mx; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }

        return dp[mx];
    }
};