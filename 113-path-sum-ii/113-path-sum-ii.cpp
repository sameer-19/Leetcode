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
    void solve(TreeNode* root,int &target,vector<int>&res,vector<vector<int>> &ans)
    {
        if(!root) return;
        
        if(!root->left and !root->right)
        {
            res.push_back(root->val);
            target-=root->val;
            if(target==0) ans.push_back(res);
            res.pop_back();
            target+=root->val;
            return;
        }
        
        target-=root->val;
        res.push_back(root->val);
        solve(root->left,target,res,ans);
        
        solve(root->right,target,res,ans);
        
        target+=root->val;
        res.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        vector<int> res;
        
        solve(root,targetSum,res,ans);
        
        return ans;
    }
};