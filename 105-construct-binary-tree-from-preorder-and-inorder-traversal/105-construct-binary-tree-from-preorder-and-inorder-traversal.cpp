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
    
    int idx;
    map<int,int> mp;
    
    TreeNode* solve(int left,int right,vector<int>& preorder)
    {
        if(left>right) return NULL;
        
        int index=idx;
        int rootValue = preorder[idx++];
        TreeNode* root= new TreeNode(rootValue);
        
        root->left = solve(left,mp[preorder[index]]-1,preorder);
        
        root->right = solve(mp[preorder[index]]+1,right,preorder);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx=0;
        int i,n=preorder.size();
        for(i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        return solve(0,n-1,preorder);
    }
};