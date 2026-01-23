class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mpp;
        for(auto x:strs){
            string temp=x;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mpp){
            vector<string> temp;
            ans.push_back(x.second);
        }
     
        return ans;

    }
};