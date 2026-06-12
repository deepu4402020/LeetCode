class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int ans = 0;
        unordered_map<int, int> types;

        for (int r = 0; r < n; r++) {
            types[fruits[r]]++;

            while (types.size() > 2) {
                types[fruits[l]]--;
                if (types[fruits[l]] == 0) {
                    types.erase(fruits[l]);
                }

                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};