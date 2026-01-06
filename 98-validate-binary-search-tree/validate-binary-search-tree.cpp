/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(TreeNode* root,vector<int>& order){
        if(root==NULL) return ;

        solve(root->left,order);
        order.push_back(root->val);
        solve(root->right,order);
        return;
    }

bool isStrictlyIncreasing(const vector<int>& v) {
    return is_sorted(v.begin(), v.end()) &&
           adjacent_find(v.begin(), v.end()) == v.end();
}
public:
    bool isValidBST(TreeNode* root) {
      
        vector<int> order;
       solve(root,order);
       return isStrictlyIncreasing(order);
        
    }
};