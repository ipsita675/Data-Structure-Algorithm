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
public:
    bool same(TreeNode* root, TreeNode* subroot){
        if(!root && !subroot)return true;
        if(!root || !subroot)return false;

        return root->val==subroot->val && 
                same(root->right,subroot->right) &&
                same(root->left,subroot->left);

    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root)return false;
        if(!subroot)return false;

        return same(root,subroot) ||
                isSubtree(root->left,subroot) || 
                isSubtree(root->right,subroot);
    }
};