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
        ListNode* tmp=head;
        
        int total=0;
        while(tmp) { total++; tmp=tmp->next;}
        
        if(total==1) return tmp;
        
        int reach=total-n,cnt=0;
        if(reach==0) return head->next;
        
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