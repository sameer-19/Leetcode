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
    
    ListNode* sumTwoList(ListNode* l1,ListNode* l2)
    {
        ListNode* ans=new ListNode();
        ListNode* tmp=ans;
        
        int c=0;
        
        while(l1 and l2)
        {
            int sum=l1->val + l2->val + c;
            
            ListNode* p = new ListNode(sum%10);
            c=sum/10;
            
            tmp->next=p;
            tmp=tmp->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1)
        {
            int sum=l1->val + c;
            
            ListNode* p = new ListNode(sum%10);
            c=sum/10;
            
            tmp->next=p;
            tmp=tmp->next;
            l1=l1->next;
        }
        
        while(l2)
        {
            int sum=l2->val + c;
            
            ListNode* p = new ListNode(sum%10);
            c=sum/10;
            
            tmp->next=p;
            tmp=tmp->next;
            l2=l2->next;
        }
        
        while(c>0)
        {
            int sum= c;
            
            ListNode* p = new ListNode(sum%10);
            c=sum/10;
            
            tmp->next=p;
            tmp=tmp->next;
        }
        
        return ans->next;
    }
    
    ListNode* reverseList(ListNode* l)
    {
        if(!l) return l; 
        ListNode* ans = new ListNode();
        ListNode* prev = NULL;
        
        while(l and l->next)
        {
            ListNode* temp = l->next;
            l->next = prev;
            prev=l;
            l=temp;
        }
        l->next=prev;
        
        return l;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseList(l1);
        
        l2 = reverseList(l2);
        
        ListNode* tmp = sumTwoList(l1,l2);
        
        ListNode* ans = reverseList(tmp);
        
        return ans;
    }
};