class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0}; // count of 'a', 'b', 'c'
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == 'a') count[0]++;
            if (s[right] == 'b') count[1]++;
            if (s[right] == 'c') count[2]++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right;
                if (s[left] == 'a') count[0]--;
                if (s[left] == 'b') count[1]--;
                if (s[left] == 'c') count[2]--;
                left++;
            }
        }
        return res;
    }
};