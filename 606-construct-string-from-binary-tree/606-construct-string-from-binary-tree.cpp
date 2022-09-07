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
    string solve(TreeNode* root)
    {
        if(!root) return "()";
        
        if(!root->left and !root->right)
        {
            string s="(";
            s+=to_string(root->val);
            s+=")";
            return s;
        }
        
        string result = "(" + to_string(root->val);
        // result+="(";
        
        if(root->left || root->right)
        result+=solve(root->left);
        
        if(root->right)
        result+=solve(root->right);
        
        result+=")";
        
        return result;
    }
    
    string tree2str(TreeNode* root) {
        string ans=to_string(root->val);
        
        if(root->left || root->right)
        ans+=solve(root->left);
        
        if(root->right)
        ans+=solve(root->right);
        
        return ans;
    }
};