class Solution {
public:
    bool isPalindromic(string s) {
        string bin;

        for(char& ch : s) {
            int ascii = ch;
            string t;
            
            while(ascii > 0) {
                int b = ascii % 2;
                t.push_back(b + '0');
                ascii /= 2;
            } 
            
            if(t.length() > 8)
                t.resize(8);
            
            if(t.length() < 8)
                t += string(8 - t.length(), '0');

            reverse(begin(t), end(t));
            bin += t;
        }

        int l = 0, r = bin.length() - 1;

        while(l <= r) 
            if(bin[l++] != bin[r--])
                return false;

        return true;
    }
};