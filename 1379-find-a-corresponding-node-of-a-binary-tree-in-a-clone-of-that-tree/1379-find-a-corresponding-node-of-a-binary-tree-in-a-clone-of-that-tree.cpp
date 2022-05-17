/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* solve(TreeNode* cloned,TreeNode* target)
    {
        if(!cloned) return NULL;
        if(cloned->val==target->val) return cloned;
        
        TreeNode* left=solve(cloned->left,target);
        
        if(left) return left;
        
        TreeNode* right=solve(cloned->right,target);
        
        if(!left) return right;
        else return left;
        
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)     {
        return solve(cloned,target);
    }
};