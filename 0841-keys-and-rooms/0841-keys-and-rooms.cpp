class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;
        int ans = 1;  

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key : rooms[room]) {
                if (!vis[key]) {
                    vis[key] = 1;
                    q.push(key);
                    ans++;   
                }
            }
        }

        return (ans == n) ? true : false;
    }
};