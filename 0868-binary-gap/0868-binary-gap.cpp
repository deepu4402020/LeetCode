class Solution {
public:
    int binaryGap(int n) {

        int prev = -1, pos = 0,ans=0;

        while (n) {
            if ((n & 1) == 1) {
                if (prev != -1) {
                    ans = max(ans, pos - prev); 
                }
                prev = pos;
            }
            n >>= 1;
            pos++;
        }

        return  ans;
    }
};