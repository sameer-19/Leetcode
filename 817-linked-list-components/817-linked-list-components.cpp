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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        ListNode* tmp=head;
        
        int ans=0,flag=0;
        
        while(tmp!=NULL)
        {
            bool z=binary_search(nums.begin(),nums.end(),tmp->val);
            // cout<<z<<" ";
            if(z and flag==0)
            {
                ans++;
                flag=1;
            }
            else if(z)
            {
                // continue;
            }
            else
            {
                flag=0;
            }
            tmp=tmp->next;
        }
        
        return ans;
    }
};