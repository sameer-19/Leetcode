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
    TreeNode* solve(int l,int r,vector<int> &nums)
    {
        if(l>r) return NULL;
        int mid= l + (r-l)/2;
        
        TreeNode* middle=new TreeNode(nums[mid]);
        
        middle->left=solve(l,mid-1,nums);
        middle->right=solve(mid+1,r,nums);
        
        return middle;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};