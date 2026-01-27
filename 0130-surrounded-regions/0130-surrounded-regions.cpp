class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> que;

        vector<pair<int, int>> d_idx = {
            {-1, 0}, {0, -1}, {0, 1}, {1, 0}
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (board[i][j] == 'X' || vis[i][j]) continue;

                vector<pair<int, int>> region;
                bool surrounded = true;

                que.push({i, j});
                vis[i][j] = 1;

                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();

                    region.push_back({x, y});

                    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) 
                        surrounded = false;
                    

                    for (auto [dx, dy] : d_idx) {
                        int ni = x + dx;
                        int nj = y + dy;

                        if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                            board[ni][nj] == 'O' && !vis[ni][nj]) {

                            vis[ni][nj] = 1;
                            que.push({ni, nj});
                        }
                    }
                }

                if (surrounded) {
                    for (auto [x, y] : region) {
                        board[x][y] = 'X';
                    }
                }
            }
        }
    }
};