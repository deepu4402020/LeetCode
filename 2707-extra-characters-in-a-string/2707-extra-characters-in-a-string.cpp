class Solution {
private:
    int dp[51];

    int solve(set<string>& dict, int i, string &s) {
        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];


        int ans = 1 + solve(dict, i + 1, s);

        for (auto &w : dict) {
            if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
                ans = min(ans, solve(dict, i + w.size(), s));
            }
        }

        return dp[i] = ans;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));

        set<string> st(dictionary.begin(), dictionary.end());

        return solve(st, 0, s);
    }
};