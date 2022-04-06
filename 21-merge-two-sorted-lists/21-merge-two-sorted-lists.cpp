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
    ListNode* solve(ListNode* ans,ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            ans->next=l2;
            return ans->next;
        }
        if(l2==NULL)
        {
            ans->next=l1;
            return ans->next;
        }
        if((l1->val)<=(l2->val))
        {
            ListNode* z=new ListNode(l1->val);
            ans->next=z;
            ans=ans->next;
            l1=l1->next;
            solve(ans,l1,l2);
        }
        else
        {
            ListNode* z=new ListNode(l2->val);
            ans->next=z;
            ans=ans->next;
            l2=l2->next;
            solve(ans,l1,l2);
        }
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        return solve(ans,l1,l2);
    }
};