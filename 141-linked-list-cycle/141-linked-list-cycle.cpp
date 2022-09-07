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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow=head,*fast=head->next;
        
        while(slow and fast and fast->next)
        {
            if(slow==fast) break;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(slow!=fast) return false;
        
        return true;
    }
};