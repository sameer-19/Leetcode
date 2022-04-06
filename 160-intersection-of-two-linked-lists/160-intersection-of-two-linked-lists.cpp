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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode* tmp=headA;
        while(tmp)
        {
            s.insert(tmp);
            tmp=tmp->next;
        }
        
        tmp=headB;
        
        while(tmp)
        {
            if(s.find(tmp)!=s.end()) return tmp;
            tmp=tmp->next;
        }
        return NULL;
    }
};