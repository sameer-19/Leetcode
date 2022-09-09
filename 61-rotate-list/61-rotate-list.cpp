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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tmp=head;
        
        int total=0;
        
        while(tmp)
        {
            total++;
            tmp=tmp->next;
        }
        
        if(k%total==0) return head;
        k%=total;
        int cnt=total-k;
        
        tmp=head;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=head;
        
        tmp=head;
        
        while(tmp)
        {
            cnt--;
            if(cnt==0)
            {
                head=tmp->next;
                tmp->next=NULL;
                break;
            }
            tmp=tmp->next;
        }
        
        
        return head;
    }
};