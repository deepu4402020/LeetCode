class Solution {
public:
    int dist(int a, int b) {
        if (a == 26 || b == 26) 
            return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.length();
        vector<int> dp(27, 1e9);
        dp[26] = 0;
        int prev = word[0] - 'A';

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            vector<int> next_dp(27, 1e9);
            for (int free = 0; free < 27; ++free) {
                if (dp[free] >= 1e9) 
                    continue;
                next_dp[free] = min(next_dp[free], dp[free] + dist(prev, cur));
                next_dp[prev] = min(next_dp[prev], dp[free] + dist(free, cur));
            }
            dp = next_dp;
            prev = cur;
        }

        int res = 1e9;
        for (int v : dp) 
            res = min(res, v);
        return res;
    }
};