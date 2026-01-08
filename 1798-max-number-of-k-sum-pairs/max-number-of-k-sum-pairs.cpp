class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
       map<int,int>mpp;
        int l=0,ans=0;
        for(int r=0;r<n;r++){
           
           if(mpp[k-nums[r]]){
                mpp[k-nums[r]]--;ans++;
           }else{
                mpp[nums[r]]++;
           }
        } 
        return ans; 
    }
};