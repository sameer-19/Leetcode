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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *cur = head;
        
        while(cur)
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        head = reverse(head);
        
        int carry = 0;
        temp = head;
        
        while(head)
        {
            int value = head->val;
            value*=2;
            head->val = (value+carry)%10;
            carry = (value+carry)/10;
            // to store the previous pointer
            prev = head;
            
            head = head->next;
        }
        
        while(carry>0)
        {
            ListNode* node = new ListNode(carry%10);
            prev->next = node;
            carry/=10;
            
            prev = prev->next;
        }
        
        head = reverse(temp);
        
        return head;
    }
};