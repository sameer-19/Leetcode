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
        int cnt=0;
        ListNode* pt=head;
        
        while(pt) { ++cnt; pt=pt->next;}
        
        cnt/=2;
        pt=head;
        while(pt and cnt)
        {
            cnt--;
            pt=pt->next;
        }
        return pt;
    }
};