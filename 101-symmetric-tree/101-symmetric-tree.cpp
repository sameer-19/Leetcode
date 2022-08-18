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
    bool solve(TreeNode* leftNode,TreeNode* rightNode)
    {
        if(!leftNode and !rightNode) return true;
        
        if(!leftNode || !rightNode) return false;
        
        if(leftNode->val!=rightNode->val) return false;
        
        return (solve(leftNode->left,rightNode->right) && solve(leftNode->right,rightNode->left));
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        if(!root->left and !root->right) return true;
        
        if(root->left && root->right)
        {
            return solve(root->left,root->right);
        }
        
        return false;
    }
};