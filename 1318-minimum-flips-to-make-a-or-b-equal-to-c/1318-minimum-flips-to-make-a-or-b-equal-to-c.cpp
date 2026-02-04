class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while (a > 0 || b > 0 || c > 0) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if (cbit == 0) {
                ans += abit + bbit;
            } else {
                if (abit == 0 && bbit == 0)
                    ans++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};