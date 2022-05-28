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
    ListNode* getMid(ListNode* head)
    {
        ListNode* midPrev=NULL;
        while(head && head->next)
        {
            midPrev = (midPrev==NULL) ? head : midPrev->next;
            head=head->next->next;
        }
        ListNode* mid=midPrev->next;
        midPrev->next=NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* ptr=&dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val){
                ptr->next=l1;
                l1=l1->next;
            }
            else {
                ptr->next=l2;
                l2=l2->next;
            }
            ptr=ptr->next;
        }
        if(l1) ptr->next=l1;
        else ptr->next=l2;
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=getMid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
};