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
    int solve(TreeNode* root, int flag)
    {
        if(!root) return 0;
        
        int sum = 0;
        
        if(!root->left and !root->right and flag==1) sum+=root->val;
        
        sum+=solve(root->left, 1);
        sum+=solve(root->right, 0);
        
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,0);
    }
};