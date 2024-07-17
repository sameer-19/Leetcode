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
    TreeNode* deleteNodeAndCreateTree(TreeNode* node,vector<TreeNode*> &list) {
        if(!node) return nullptr;
        
        TreeNode* leftChild = deleteNodeAndCreateTree(node->left, list);
        TreeNode* rightChild = deleteNodeAndCreateTree(node->right, list);
        
        if(node->val!=0) {
            node->left = leftChild;
            node->right = rightChild;
            return node;
        }
        
        if(leftChild) list.push_back(leftChild);
        if(rightChild) list.push_back(rightChild);
        
        return nullptr;
    }
    
    void traversalToMakeDeleteNodeValueZero(TreeNode* node, map<int,int> mp) {
        if(!node) return;
        
        if(mp[node->val]) node->val = 0;
        
        traversalToMakeDeleteNodeValueZero(node->left,mp);
        traversalToMakeDeleteNodeValueZero(node->right,mp);
        
        return;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        map<int,int> deleteNodes;
        for(auto node: to_delete) {
            deleteNodes[node]=1;
        }
        
        traversalToMakeDeleteNodeValueZero(root, deleteNodes);
        
        vector<TreeNode*> ans;
        
        TreeNode* finalResult = deleteNodeAndCreateTree(root, ans);
        
        if(finalResult) ans.push_back(finalResult);
        
        return ans;
    }
};