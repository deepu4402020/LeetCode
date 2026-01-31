class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        queue<pair<int,int>> q;
        vector<vector<int>> vis;
        q.push({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            ans.push_back(nums[i][j]);
             if (j == 0 && i + 1 < nums.size()) {
                q.push({i + 1, 0});
            }
            if (j + 1 < nums[i].size()) {
                q.push({i, j + 1});
            }
           
        }
        return ans;
    }
};