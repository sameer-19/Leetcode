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
    int deepestLeavesSum(TreeNode* root) {
        int ans=0,sum,i;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        while(!q.empty())
        {
            sum=0;
            int sz=q.size();
            
            for(i=0;i<sz;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                
                sum+=p->val;
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            
            ans=sum;
        }
        
        return ans;
    }
};