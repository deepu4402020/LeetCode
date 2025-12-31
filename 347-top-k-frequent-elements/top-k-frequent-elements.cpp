class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};