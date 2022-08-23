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
    bool isPalindrome(ListNode* head) {
        ListNode* tmp=head;
        
        int cnt=0;
        
        while(tmp)
        {
            cnt++;
            tmp=tmp->next;
        }
        
        int c=0;
        
        ListNode* prev=NULL,*cur=head;
        while(c<(cnt/2))
        {
            c++;
            ListNode* z=cur->next;
            cur->next=prev;
            prev=cur;
            cur=z;
        }
        
        if(cnt%2==0)
        {   
            while(cur)
            {
                if(prev->val!=cur->val)
                {
                    return false;
                }
                prev=prev->next;
                cur=cur->next;
            }
            
            return true;
        }
        else
        {
            cur=cur->next;
            while(cur)
            {
                if(prev->val!=cur->val)
                {
                    return false;
                }
                prev=prev->next;
                cur=cur->next;
            }
            
            return true;   
        }
            
    }
};