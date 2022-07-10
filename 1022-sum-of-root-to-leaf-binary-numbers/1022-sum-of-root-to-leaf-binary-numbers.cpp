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
    int result=0;
    
    void solve(TreeNode* root,int &ans)
    {
        if(!root) return;
        
        if(!root->left and !root->right)
        {
            ans*=2;
            ans+=root->val;
            
            result+=ans;
            
            ans-=root->val;
            ans/=2;
            
            return;
        }
        
        ans=(ans*2)+root->val;
        
        solve(root->left,ans);
        
        solve(root->right,ans);
        
        ans-=root->val;
        ans/=2;
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        
        int ans=0;
        
        solve(root,ans);
        
        return result;
    }
};