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
    int summation(TreeNode* root,int& ans){
        if(!root)return 0;

        int lf=max(0,summation(root->left,ans));
        int rh=max(0,summation(root->right,ans));
        ans=max(ans,lf+rh+root->val);

        return root->val+max(lf,rh);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        summation(root,ans);
        return ans;
    }
};