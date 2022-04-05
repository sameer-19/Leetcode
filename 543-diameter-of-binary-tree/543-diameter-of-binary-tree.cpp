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
    int mx=0;
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        mx=max(mx,lh+rh);
        return max(lh,rh)+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=solve(root);
        return mx;
    }
};