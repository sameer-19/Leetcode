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
    TreeNode* solve(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* res=new TreeNode(root->val);
        
        res->left=solve(root->right);
        res->right=solve(root->left);
        
        return res;
        
    }
    
    
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        
        
        return solve(root);
    }
};