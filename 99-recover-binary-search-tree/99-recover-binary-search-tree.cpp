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
    vector<int> v1,v2;
    
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        inorder(root->left);
        
        v1.push_back(root->val);
        
        inorder(root->right);
    }
    
    void modifyInorder(TreeNode* root,int &i)
    {
        if(!root) return;
        
        modifyInorder(root->left,i);
        
        root->val=v2[i++];
        
        modifyInorder(root->right,i);
        
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        v2=v1;
        sort(v2.begin(),v2.end());
        
        int id1=-1,id2=-1;
        
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
            {
                if(id1==-1) id1=v1[i];
                else id2=v1[i];
            }
        }
        // cout<<id1<<" "<<id2;
        
        int i=0;
        modifyInorder(root,i);
        
    }
};