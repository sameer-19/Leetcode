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
    bool check(TreeNode* root,TreeNode* sub)
    {
        if(!root and !sub) return true;
        if(!root || !sub) return false;
        
        if(root->val!=sub->val) return false;
        
        return check(root->left,sub->left)&check(root->right,sub->right);
    }
    
    void dfs(TreeNode* root,TreeNode* subRoot,bool &flag)
    {
        if(!root) return;
        if(flag) return;
        
        dfs(root->left,subRoot,flag);
        
        bool res = check(root,subRoot); 
        if(res) flag=1;
        
        dfs(root->right,subRoot,flag);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag=0;
        
        dfs(root,subRoot,flag);
        
        return flag;
    }
};