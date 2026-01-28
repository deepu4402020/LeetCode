class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        queue<pair<string,int>> q;
        q.push({startGene, 0});

        unordered_set<string> used;
        used.insert(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();

            if (curr == endGene) return level;

            for (int i = 0; i < 8; i++) {
                char original = curr[i];
                for (char g : genes) {
                    if (g == original) continue;

                    curr[i] = g;
                    if (st.count(curr) && !used.count(curr)) {
                        used.insert(curr);
                        q.push({curr, level + 1});
                    }
                }
                curr[i] = original;
            }
        }
        return -1;
    }
};