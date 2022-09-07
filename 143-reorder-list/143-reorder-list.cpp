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
    void reorderList(ListNode* head) {
        vector<int> v;
        
        ListNode* ptr=head;
        
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        
        int i=1,c=0,j=v.size()-1;
        
        head->val = v[0];
        head=head->next;
        
        while(i<=j and head)
        {
            if(c%2==0)
            {
                head->val=v[j--];
            }
            else
            {
                head->val=v[i++];
            }
            head=head->next;
            c++;
        }
        
        return;
    }
};