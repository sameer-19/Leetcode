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
    
    void solve(TreeNode* root,vector<int> &ans)
    {
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        
        return;
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        vector<int> res;
        
        solve(root,res);
        
        int n=res.size();
        for(int i=1;i<n;i++)
        {
            ans=min(ans,res[i]-res[i-1]);
        }
        
        return ans;
    }
};