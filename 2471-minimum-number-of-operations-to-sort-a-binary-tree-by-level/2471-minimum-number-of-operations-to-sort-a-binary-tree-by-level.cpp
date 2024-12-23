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
    int findOperations(vector<int> &v)
    {
        int n = v.size();
        vector<int> temp(v);
        sort(temp.begin(), temp.end());
        
        unordered_map<int,int> mp1;
        
        for(int i=0;i<n;i++)
        {
            mp1[v[i]] = i;
        }
        
        int cnt = 0, i = 0, change = 1;
        
        while(i<n)
        {
            if(v[i]!=temp[i])
            {
                cnt++;
                int curIdx = mp1[temp[i]];
                mp1[v[i]] = curIdx;
                swap(v[curIdx], v[i]);
            }
            i++;
        }
        
        return cnt;
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            ans+=findOperations(v);
        }
        
        return ans;
    }
};