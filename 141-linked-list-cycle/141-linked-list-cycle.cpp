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
        if(head==NULL) return false;
        if(head->next==head) return true;
        ListNode *slow,*fast;
        slow=head;fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            if(fast==slow) { return true;}
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};