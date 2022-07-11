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
    int findMax(vector<int> &nums,int l,int r)
    {
        int mx=INT_MIN;
        int idx=0;
        
        for(int i=l;i<=r;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                idx=i;
            }
        }
            
        return idx;
    }
    
    TreeNode* solve(vector<int>& nums,int left,int right)
    {
        if(left>right) return NULL;
        if(left==right) return new TreeNode(nums[left]);
        
        int idx=findMax(nums,left,right);
        TreeNode* root = new TreeNode(nums[idx]);
        
        root->left = solve(nums,left,idx-1);
        root->right = solve(nums,idx+1,right);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int i,n=nums.size();
        
        return solve(nums,0,nums.size()-1); 
    }
};