/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q, map<TreeNode*, int>& mpp,int & ans) {
        
        if (root == NULL) {
            return NULL;
        }
        if(root==p ||root==q){
            return root;
        }
      
        TreeNode* left=  solve(root->left, p, q, mpp,ans) ;
        TreeNode* right = solve(root->right, p, q, mpp,ans);
        
        if(left&&right){//both have some value=> found both p,q and it's LCA
            return root;
        }
        return (left) ? left :right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, int> mpp;
        int ans=-1;
        //NO NEED TO MAP, ANS VARIBLE
        return  solve(root, p,q, mpp,ans);
    }
};