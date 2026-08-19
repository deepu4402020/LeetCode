class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto it : reservedSeats){
            int row = it[0];
            int seatNo = it[1];
            if(seatNo >= 2 && seatNo <= 9){
                mp[row] |= (1 << (seatNo - 2));
            }
        }
        int sol = (n - mp.size()) * 2;
        int leftMask = 0b00001111;
        int midMask = 0b00111100;
        int rightMask = 0b11110000;
        for(auto it : mp){
            int currMask = it.second;
            bool left = ((currMask & leftMask) == 0);
            bool mid = ((currMask & midMask) == 0);
            bool right = ((currMask & rightMask) == 0);
            if(left && right){
                sol += 2;
            }else if(left || mid || right){
                sol++;
            }
        }
        return sol;
    }
};