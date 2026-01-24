class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        for(int i=0;i<s.length();i++){
            int val = s[i];
            if(val>=97){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                    v++;
                }
                else{
                    c++;
                }
            }
        }
        if(c==0){
            return 0;
        }
        else{
            return v/c;
        }
    }
};