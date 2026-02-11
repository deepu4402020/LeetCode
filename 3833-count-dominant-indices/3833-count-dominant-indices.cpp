class Solution {
public:
    int dominantIndices(vector<int>& a) {{{{{{{{{
        int n = a.size(), sum = 0, cnt = 0;
        for (int i = n - 1; i > 0; i--) {{{{{{{{
            sum += a[i];
            if (a[i-1] > sum / (n - i)) {
                ++cnt;
            }}}}}}}}
        }
        return cnt;}}}}}}}}
    }
};