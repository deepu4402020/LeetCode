class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<long long, long long>>> t(n, vector<pair<long long, long long>>(m, {0, 0}));
        t[0][0].first = t[0][0].second = grid[0][0];

        for (int i = 1; i < n; i++) {
            long long val = t[i - 1][0].first * grid[i][0];
            t[i][0].first = t[i][0].second = val;
        }

        for (int j = 1; j < m; j++) {
            long long val = t[0][j - 1].first * grid[0][j];
            t[0][j].first = t[0][j].second = val;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long a = t[i - 1][j].first * grid[i][j];
                long long b = t[i][j - 1].first * grid[i][j];
                long long c = t[i - 1][j].second * grid[i][j];
                long long d = t[i][j - 1].second * grid[i][j];

                t[i][j].first = max({a, b, c, d});
                t[i][j].second = min({a, b, c, d});
            }
        }

        long long ans = t[n - 1][m - 1].first;
        if (ans < 0) return -1;
        return ans % MOD;
    }
};