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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int> >> q;
        
        q.push({root,{0,0}}); // node , vertical line no. , level no.
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int line=p.second.first , level=p.second.second;
            
            mp[line][level].insert(node->val);
            
            if(node->left) q.push({node->left,{line-1,level+1}});
            if(node->right) q.push({node->right,{line+1,level+1}});
            
        }
        
        for(auto x: mp){
            vector<int> c;
            for(auto y: x.second) {
                c.insert(c.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(c);
        }
        return ans;
    }
};