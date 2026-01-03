class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            //position to attach the remaining
            TreeNode* succ = root->right;
            while (succ->left)
                succ = succ->left;

            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};