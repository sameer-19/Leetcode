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
    int ans1=INT_MIN,ans2=INT_MIN;
    int solve1(TreeNode* root)
    {
        if(root==NULL) return INT_MAX;
        int lh=min(root->val,solve1(root->left));
        int rh=min(root->val,solve1(root->right));
        ans1=max(ans1,abs(root->val-min(lh,rh)));
        int mn=min(lh,rh);
        return mn;
    }
    int solve2(TreeNode* root)
    {
        if(root==NULL) return INT_MIN;
        int lh=max(root->val,solve2(root->left));
        int rh=max(root->val,solve2(root->right));
        ans2=max(ans2,abs(root->val-max(lh,rh)));
        int mx=max(lh,rh);
        return mx;
    }
    int maxAncestorDiff(TreeNode* root) {
        solve1(root);
        solve2(root);
        int ans=max(ans1,ans2);
        return ans;
    }
};