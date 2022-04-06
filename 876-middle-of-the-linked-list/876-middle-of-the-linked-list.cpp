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
    ListNode* middleNode(ListNode* head) {
        int total=0;
        if(head->next==NULL) return head;
        
        ListNode* tmp=head;
        while(tmp) { total++; tmp=tmp->next;}
        
        int middle=(total/2)+1;
        
        tmp=head;
        int c=1;
        
        while(c<middle)
        {
            c++;
            tmp=tmp->next;
        }
        return tmp;
    }
};