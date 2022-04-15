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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return root;
        
        int value=root->val;
        
        if(value<low)
        {
            return trimBST(root->right,low,high);
        }
        if(value>high)
        {
            return trimBST(root->left,low,high);
        }
        
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        
        return root;
    }
};