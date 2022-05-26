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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev=head,*cur=head->next;
        
        while(cur!=NULL)
        {
            if(prev->val!=cur->val)
            {
                prev->next=cur;
                cur=cur->next;
                prev=prev->next;
            }
            else
            {
                cur=cur->next;       
            }
        }
        prev->next=cur;
        
        return head;
    }
};