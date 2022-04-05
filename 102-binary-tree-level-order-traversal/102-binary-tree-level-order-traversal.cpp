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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> v;
        
        while(!q.empty())
        {
            int qsize=q.size();
            vector<int> c;
            for(int i=0;i<qsize;i++)
            {
                auto z=q.front();
                q.pop();
                
                if(z->left) q.push(z->left);
                if(z->right) q.push(z->right);
                
                c.push_back(z->val);
            }
            v.push_back(c);
        }
        return v;
    }
};