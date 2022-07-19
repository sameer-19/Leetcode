/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        
        ListNode* slow=head,*fast=head->next;
        
        while(fast and fast->next)
        {
            if(slow==fast) break;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(!fast) return NULL;
        
        slow=head;
        fast=fast->next;
        
        while(fast and slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast;
    }
};