class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
                deque<int> dq;

            for(int j=i;j<n;j++){

               if(dq.empty()){
                dq.push_front(nums[j]);
               }
               else if(nums[j]>dq.front()){
                dq.push_front(nums[j]);
               }
               else if(nums[j]<dq.back()){
                dq.push_back(nums[j]);
               }
                ans+=(dq.front()-dq.back());

            }
        }
        return ans;
    }
};