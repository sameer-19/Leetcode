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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head) return NULL;
        
        if(!head->next) return head;
        
        ListNode* left = new ListNode(0),*right = new ListNode(0);
        ListNode* left_begin = left,*right_begin = right;
        
        ListNode* tmp = head,*prev1 = left, *prev2 = right;
        
        while(tmp)
        {
            if(tmp->val>=x)
            {
                right->next= tmp;
                prev2=tmp;
                right=right->next;
            }
            else
            {
                left->next=tmp;
                prev1=tmp;
                left=left->next;
            }
            tmp=tmp->next;
        }
        
        prev1->next = right_begin->next;
        prev2->next=NULL;
        
        return left_begin->next;
    }
};