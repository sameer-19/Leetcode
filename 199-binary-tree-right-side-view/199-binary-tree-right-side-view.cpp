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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(!root) return ans;
        
        int i;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size(),value;
            
            for(i=0;i<sz;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                
                value=p->val;
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                
            }
            ans.push_back(value);
            
        }
        
        return ans;
    }
};