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
    TreeNode* cur;
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* ans=new TreeNode(0);
        cur=ans;
        
        inorder(root);
        
        return ans->right;
    }
    
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        
        cur->right=root;
        root->left=NULL;
        cur=cur->right;
        
        // v.push_back(root);
        inorder(root->right);
    }
    
};