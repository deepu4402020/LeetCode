class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        int cnt=1,ans=1;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int x=i;
                 while(st.find(x+1)!=st.end()){
                    cnt++;x=x+1;
                }
            }
            
            ans=max(ans, cnt);cnt=1;
        }
        return ans;
    }
};