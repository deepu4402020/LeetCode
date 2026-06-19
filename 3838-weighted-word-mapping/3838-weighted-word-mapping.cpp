class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string str = "";
        for (auto &s : words) {
            int total = 0;
            for (char c : s) {
                total += weights[c - 'a'];
            }
            str += char('z' - (total % 26));
        }
        return str;
    }
};