class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> mpp;
        vector<int> trav;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }
        bool up = true;

        for (auto [k,x] : mpp) {
            if (up)
                reverse(x.begin(), x.end());

            trav.insert(trav.end(), x.begin(), x.end());

            up = !up;
        }
        return trav;
    }
};