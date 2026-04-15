class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int stps = n;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int r = (i - startIndex + n) % n;
                int l  = (startIndex - i + n) % n;
                stps = min(stps, min(r, l));
            }
        }

        return stps == n ? -1 : stps;
    }
};