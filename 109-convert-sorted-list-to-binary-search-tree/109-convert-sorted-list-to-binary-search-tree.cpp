/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int> &v,int l,int r)
    {
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* middle = new TreeNode(v[mid]);
        
        middle->left=solve(v,l,mid-1);
        middle->right=solve(v,mid+1,r);
        
        return middle;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        
        ListNode* node=head;
        while(node)
        {
            v.push_back(node->val);
            node = node->next;
        }
        
        int left=0,right=v.size()-1;
        
        return solve(v,left,right);
        
    }
};