class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        int i = 0, j = 0;
        int firstOcc = -1;

        for (; i < n1 && j < n2; i++) {
            if (haystack[i] == needle[j]) {
                if (firstOcc == -1) firstOcc = i;

                if (j == n2 - 1)
                    return firstOcc;

                j++;
            } else {
                if (firstOcc != -1) {
                    i = firstOcc;
                }
                firstOcc = -1;
                j = 0;
            }
        }
        return -1;
    }
};