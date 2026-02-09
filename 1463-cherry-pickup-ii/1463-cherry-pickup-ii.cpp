class Solution {
public:
    int n, m;
     int dp[71][71][71];

    int solve(vector<vector<int>>& grid, int i, int j1, int j2) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solve(grid, i + 1, j1 + dj1, j2 + dj2);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp,-1,sizeof(dp));

        return solve(grid, 0, 0, m - 1);
    }
};