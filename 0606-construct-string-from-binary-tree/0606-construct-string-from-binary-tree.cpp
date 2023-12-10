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
    void solve(TreeNode* root,string &s)
    {
        if(!root) 
        {
            return;
        }
        
        if(!root->left and !root->right)
        {
            s+='('+to_string(root->val)+')';
            return;
        }
        
        s+='(';
        
        s+=to_string(root->val);
        
        if(root->left)
        {
            solve(root->left,s);
        }
        else
        {
            s+="()";
        }
        
        solve(root->right,s);
        
        s+=')';
    }
    
    string tree2str(TreeNode* root) {
        string ans="";
        ans+=to_string(root->val);
        
        if(!root->left and !root->right)
        {
            return ans;
        }
        
        if(root->left) solve(root->left,ans);
        else
        {
            ans+="()";
        }
        
        solve(root->right,ans);
        return ans;
    }
};