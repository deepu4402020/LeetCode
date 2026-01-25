class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char x:s){
            if(!stk.empty()&&x==stk.top())
                stk.pop();
            
            else{
             stk.push(x);
            }
        }
        string ans;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};