class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();

        map<int,vector<int>>mpp;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                mpp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto &x:mpp){
            for(auto y:x.second){
                ans.push_back(y);
            }
        }
        return ans;
    }
};