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
    
    bool solve(TreeNode* root,long min,long max){
        if(!root) return true;
        
        if(root->val<=min || root->val>=max) return false;
        
        return (solve(root->left,min,root->val)&solve(root->right,root->val,max));
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return solve(root,-1e12,1e12);
    }
};