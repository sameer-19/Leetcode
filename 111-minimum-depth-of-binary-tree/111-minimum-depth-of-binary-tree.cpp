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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        int i,ans=INT_MAX,mx=0;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            mx++;
            for(i=0;i<sz;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                
                if(!t->left and !t->right) ans=min(ans,mx);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        
        return ans;
    }
};