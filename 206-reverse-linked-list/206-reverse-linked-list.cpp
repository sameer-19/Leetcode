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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev=head,*cur= head->next,*preprev=NULL;
        
        while(cur)
        {
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev->next = preprev;
            preprev = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
};