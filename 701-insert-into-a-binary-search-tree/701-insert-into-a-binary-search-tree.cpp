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
    void solve(TreeNode* root,int val){
        if(!root->left and !root->right)
        {
            if(root->val>val)
            {
                TreeNode* node=new TreeNode(val);
                root->left=node;
                return;
            }
            else
            {
                TreeNode* node=new TreeNode(val);
                root->right=node;
                return;
            }
        }
            
        if(root->val>val)
        {
            if(root->left) solve(root->left,val);
            else 
            {
                TreeNode* node=new TreeNode(val);
                root->left=node;
                return;
            }
        }
        else
        {
            if(root->right) solve(root->right,val);
            else
            {
                TreeNode* node=new TreeNode(val);
                root->right=node;
                return;
            }
        }
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(!root) return node;
        
        TreeNode* result=root;
        
        solve(root,val);
        
        return result;
    }
};