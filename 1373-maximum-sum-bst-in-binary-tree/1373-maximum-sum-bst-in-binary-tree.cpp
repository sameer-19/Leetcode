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
    int result;
    // {smallest_num,largest_num,sum}
    
    vector<int> dfs(TreeNode* root)
    {
        if(!root) return {INT_MAX,INT_MIN,0};
        
        vector<int> left,right;
        
        left = dfs(root->left);
        
        right= dfs(root->right);
        
        if(left.size()==0 || right.size()==0 || left[1]>=root->val || right[0]<=root->val) return {};
        
        result=max(result,left[2]+right[2]+root->val);
        
        return { min(left[0],root->val), max(right[1],root->val),left[2]+right[2]+root->val};
    }
    
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        
        result=0;
        dfs(root);
        
        return result;
    }
};