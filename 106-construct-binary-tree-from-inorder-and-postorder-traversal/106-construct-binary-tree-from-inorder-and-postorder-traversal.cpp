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
    unordered_map<int,int> mp;
    
    TreeNode* solve(int left,int right,vector<int> &postorder,int &idx)
    {
        // if(idx==-1) return NULL;
        if(left>right) return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx--]);
        int index= mp[root->val];
        
        root->right = solve(index+1,right,postorder,idx);
        
        root->left = solve(left,index-1,postorder,idx);
            
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i,n=inorder.size();
        
        // reverse(postorder.begin(),postorder.end());
        
        for(i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        int idx=n-1;
        
        return solve(0,n-1,postorder,idx);
    }
};