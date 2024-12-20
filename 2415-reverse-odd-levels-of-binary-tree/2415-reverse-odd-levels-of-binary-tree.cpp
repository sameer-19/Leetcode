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
    void reverseLevel(queue<TreeNode*> &q)
    {
        queue<TreeNode*> qt(q);
        int i = 0, j = q.size();
        
        vector<int> temp;
        
        while(i<j)
        {
            temp.push_back(qt.front()->val);
            qt.pop();
            i++;
        }
        i = j-1;
        
        while(i>=0)
        {
            TreeNode* cur = q.front();
            q.pop();
            cur -> val = temp[i--];
            q.push(cur);
        }
        
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            if(level%2!=0)
            {
                reverseLevel(q);
            }
            
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            level++;
        }
        
        return root;
    }
};