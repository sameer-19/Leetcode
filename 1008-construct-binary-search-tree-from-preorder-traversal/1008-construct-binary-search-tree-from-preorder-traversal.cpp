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
    TreeNode* bstFromPreorder(vector<int>& v) {
        int i,n=v.size();
        
        TreeNode* ans=new TreeNode(v[0]);
        TreeNode* temp = ans;
        
        for(i=1;i<n;i++)
        {
            temp=ans;
            
            while(temp)
            {
                if(!temp->left and !temp->right)
                {
                    if(temp->val>v[i])
                    {
                        TreeNode* node = new TreeNode(v[i]);
                        temp->left = node;
                        break;
                    }
                    else
                    {
                        TreeNode* node = new TreeNode(v[i]);
                        temp->right = node;  
                        break;
                    }
                }
                if(temp->val>v[i]) 
                {
                    if(temp->left) temp=temp->left;
                    else
                    {
                        TreeNode* node = new TreeNode(v[i]);
                        temp->left = node;
                        break;
                    }
                }
                else
                {
                    if(temp->right) temp=temp->right;
                    else
                    {
                        TreeNode* node = new TreeNode(v[i]);
                        temp->right = node;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};