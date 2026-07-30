class Solution {
public:
    int minimumPushes(string word) {
        if(word.length() <= 8){
            return word.size();
        }

        int n = word.length();
        int rem = n % 8;
        int div = n / 8;

        if(n < 16){
            return 8 + (2 * rem);
        }

        if(n < 24){
            return 8 + (8 * div) + (rem * (div + 1));
        }

        if(n <= 26){
            return 8 + (8 * 2) + (8 * div) + (rem * (div + 1));
        }

        return 0;
    }
};