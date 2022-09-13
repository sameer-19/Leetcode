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
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        
        int lh= depth(root->left);
        int rh= depth(root->right);
        
        return max(lh,rh)+1;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        return depth(root);
    }
};