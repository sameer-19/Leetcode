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
    int solve(TreeNode* root,int &mx)
    {
        if(!root) return 0;
        
        int leftSum = max(0,solve(root->left,mx));
        int rightSum = max(0,solve(root->right,mx));
        
        mx=max(mx,leftSum+rightSum+root->val);
        
        return max(leftSum,rightSum)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int mx=INT_MIN;
        solve(root,mx);
        
        return mx==INT_MIN ? root->val : mx;
    }
};