class Solution {
public:
    bool uniformArray(vector<int>& nums) {

        int a = *min_element(nums.begin(), nums.end());

        if(a % 2 == 1) return true;  

        for(int i : nums)
            if(i % 2 == 1) return false; 

        return true; 
    }
};