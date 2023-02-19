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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        int direction = 0;
        
        while(!q.empty())
        {
            int sz= q.size();
            vector<int> res;
            for(int i=0;i<sz;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                res.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            if(direction%2==0) ans.push_back(res);
            else
            {
                reverse(res.begin(),res.end());
                ans.push_back(res);
            }
            
            direction++;
        }
        
        return ans;
    }
};