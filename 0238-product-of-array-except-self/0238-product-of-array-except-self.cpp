class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
        vector<int> ans(n,1);
        int temp=nums[0];

        for(int i=1;i<n;i++){
            ans[i]*=temp;
            temp*=nums[i];
        }
        temp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]*=temp;
            temp*=nums[i];
        }
        return ans;
    }
};