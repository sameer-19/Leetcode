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
        vector<int> v1,v2;
        
        ListNode* tmp = head;
        
        while(tmp)
        {
            if(tmp->val>=x)
            {
                v1.push_back(tmp->val);
            }
            else
            {
                v2.push_back(tmp->val);
            }
            tmp=tmp->next;
        }
        
        tmp=head;
        int c1=0,c2=0;
        
        while(tmp)
        {
            if(c2<v2.size())
            {
                tmp->val = v2[c2++];
            }
            else
            {
                tmp->val = v1[c1++];
            }
            tmp = tmp->next;
        }
        
        return head;
    }
};