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
    void solve(TreeNode* root,vector<int> &nums)
    {
        if(!root) return;
        solve(root->left,nums);
        nums.push_back(root->val);
        solve(root->right,nums);
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        
        solve(root,v);
        
        map<int,int> mp;
        int i;
        
        for(i=0;i<v.size();i++) mp[v[i]]++;
        
        for(i=0;i<v.size();i++)
        {
            if(k-v[i]!=v[i] and mp[k-v[i]]>0) return true;
            else if(k-v[i]==v[i] and mp[v[i]]>1) return true;
        }
        
        return false;
    }
};