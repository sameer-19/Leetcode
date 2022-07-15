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
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root) return;
        
        inorder(root->left,v);
        
        v.push_back(root->val);
        
        inorder(root->right,v);
        
    }
    
    TreeNode* solve(int left,int right,vector<int> &v)
    {
        if(left>right) return NULL;
        
        int mid = left + (right-left)/2;
        
        TreeNode* midNode = new TreeNode(v[mid]);
        
        midNode->left = solve(left,mid-1,v);
        midNode->right = solve(mid+1,right,v);
        
        return midNode;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
        
        vector<int> v;
        inorder(root,v);
        
        return solve(0,v.size()-1,v);
        
    }
};