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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        
        q.push({root,0});
        
        long long ans=0,mn,mx,i;
        
        while(!q.empty())
        {
            mn=INT_MAX,mx=INT_MIN;
            long long sz=q.size();
            long long rel=q.front().second;
            for(i=0;i<sz;i++)
            {
                pair<TreeNode*,long long> p=q.front();
                q.pop();
                if(p.second-rel<mn) mn=p.second-rel;
                if(p.second-rel>mx) mx=p.second-rel;
                
                if(p.first->left) q.push({p.first->left,2*(p.second-rel) +1});
                if(p.first->right) q.push({p.first->right,2*(p.second-rel) +2});
                
            }
            ans=max(ans,mx-mn+1);
            
        }
        return ans;
        
    }
};