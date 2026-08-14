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
    int count(TreeNode* cur,int max_val,int& ct){
        if(!cur)return 0;
        if(cur->val>=max_val){
            ct++;
            max_val=cur->val;
        }

        if(cur->left)count(cur->left,max_val,ct);
        if(cur->right)count(cur->right,max_val,ct);

        return ct;
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int ct=0;
        count(root,root->val,ct);
        return ct;
    }
};