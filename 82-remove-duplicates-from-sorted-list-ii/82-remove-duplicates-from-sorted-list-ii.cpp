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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp=head,*ans=new ListNode();
        ListNode* z=ans;
        while(tmp!=NULL)
        {
            if(!tmp->next) 
            {
                ListNode* a=new ListNode(tmp->val);
                z->next=a;
                z=z->next;
                tmp=tmp->next;
            }
            else
            {
                ListNode* c=tmp->next;
                int cnt=0;
                while(c!=NULL && c->val==tmp->val)
                {
                    cnt++;
                    c=c->next;
                }
                if(cnt==0) 
                {
                    ListNode* a=new ListNode(tmp->val);
                    z->next=a;
                    z=z->next;
                    tmp=tmp->next;
                }
                else
                {
                    tmp=c;
                }
            }
        }
        
        return ans->next;
    }
};