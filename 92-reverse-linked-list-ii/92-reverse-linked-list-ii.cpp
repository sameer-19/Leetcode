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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftPrev = dummy, *cur = head, *prev=NULL;
        
        for(int i=0;i<left-1;i++)
        {
            leftPrev=cur;
            cur=cur->next;
        }
        
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev=cur;
            cur = tmp;
        }
        
        leftPrev->next->next = cur;
        leftPrev->next = prev;
        
        return dummy->next;
    }
};