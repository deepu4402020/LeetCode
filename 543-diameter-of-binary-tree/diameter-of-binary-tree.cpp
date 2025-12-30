/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, int& maxDia) {
        if (root == NULL)
            return 0;

        int l= solve(root->left,maxDia) ;
        int r= solve(root->right,maxDia);

        maxDia = max((l+r), maxDia);
         return max(l,r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        solve(root,maxDia);
        return maxDia;
    }
};