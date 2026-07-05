class Solution {
public:
    int mod = 1e9 + 7;
    int calc(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
    vector<int> solve(int i, int j, vector<string>& board,
                      vector<vector<vector<int>>>& dp) {
        if ((i < 0 || j < 0) || board[i][j] == 'X')
            return {0, 0};
        if (i == 0 && j == 0)
            return {0, 1};
        if (dp[i][j].size() > 0)
            return dp[i][j];
        vector<int> a = solve(i, j - 1, board, dp);
        vector<int> b = solve(i - 1, j - 1, board, dp);
        vector<int> c = solve(i - 1, j, board, dp);
        vector<int> mx = a;
        if (a[0] <= b[0]) {
            if (a[0] < b[0])
                mx = {b[0], b[1]};
            else
                mx = {b[0], calc(b[1], a[1])};
        }
        if (mx[0] <= c[0]) {
            if (mx[0] < c[0])
                mx = {c[0], c[1]};
            else
                mx = {c[0], calc(c[1], mx[1])};
        }
        int cost = 0;
        if (board[i][j] != 'S')
            cost = board[i][j] - '0';
        if (mx[1] > 0)
            cost += mx[0];
        return dp[i][j] = {cost, mx[1]};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m));
        return solve(n - 1, m - 1, board, dp);
    }
};