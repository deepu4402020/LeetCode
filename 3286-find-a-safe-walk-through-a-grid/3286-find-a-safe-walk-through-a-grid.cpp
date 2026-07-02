class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        vector<vector<int>> best(m, vector<int>(n, 0));

        int st = health - grid[0][0];

        if (st <= 0) return false;

        best[0][0] = st;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int currHealth = best[i][j];

            for (int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int nextHealth = currHealth - grid[nr][nc];

                if (nextHealth <= 0)
                    continue;

                if (nextHealth > best[nr][nc]) {
                    best[nr][nc] = nextHealth;
                    q.push({nr, nc});
                }
            }
        }

        return best[m - 1][n - 1] >= 1;
    }
};