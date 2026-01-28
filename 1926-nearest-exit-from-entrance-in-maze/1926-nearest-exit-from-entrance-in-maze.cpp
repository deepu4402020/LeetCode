
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[nx][ny] == '.') {

                        if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1)
                            return steps;

                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};