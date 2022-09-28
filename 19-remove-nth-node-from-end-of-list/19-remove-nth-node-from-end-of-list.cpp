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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* tmp=head;
        
        while(tmp){ cnt++; tmp=tmp->next; }
        
        if(cnt==1) return head->next;
        
        int reach=cnt-n;
        
        if(reach==0) return head->next;
        
        cnt=0;
        tmp=head;
        while(tmp)
        {
            cnt++;
            if(cnt==reach)
            {
                tmp->next=tmp->next->next;
                break;
            }
            tmp=tmp->next;
        }
        return head;
        
    }
};