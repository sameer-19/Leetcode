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
    void solve(TreeNode* root,int maxi,int &ans)
    {
        if(!root) return;
        
        if(root->val>=maxi) ans++;
        maxi=max(maxi,root->val);
        
        solve(root->left,maxi,ans);
        solve(root->right,maxi,ans);
        
        return;
    }
    
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        int ans=1;
        int mx=root->val;
        
        solve(root->left,mx,ans);
        
        solve(root->right,mx,ans);
        
        return ans;
    }
};