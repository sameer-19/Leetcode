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
    void deleteNode(ListNode* node) {
        ListNode* tmp=node,*prev=NULL;
        while(tmp->next)
        {
            prev=tmp;
            tmp->val=tmp->next->val;
            tmp=tmp->next;
        }
        prev->next=NULL;
        return;
    }
};