class Solution {
public:
    int t[100001][5][2];

    int maxProfit(vector<int>& prices) {
        int n = prices.size();  

        for(int i=0;i<n;i++){
            for(int flag=0;flag<=1;flag++){
                t[i][0][flag]=0;
            }
        }

        for(int rem=0;rem<=2;rem++){  
            for(int flag=0;flag<=1;flag++){
                t[n][rem][flag]=0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int rem = 1; rem <= 2; rem++) {
                for (int flag = 0; flag <= 1; flag++) {

                    int skip = t[i+1][rem][flag];   
                    int take = 0;

                    if (flag) {
                        take = -prices[i] + t[i+1][rem][0];
                    } else {
                        take = prices[i] + t[i+1][rem-1][1];
                    }

                    t[i][rem][flag] = max(skip, take);
                }
            }
        }
        return t[0][2][1];
    }
};