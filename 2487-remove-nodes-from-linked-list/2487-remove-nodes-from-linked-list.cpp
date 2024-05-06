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
    ListNode* removeNodes(ListNode* head) {
        stack<int> s1, s2;
        ListNode* ans = new ListNode(0);
        
        int prev = INT_MAX;
        
        while(head)
        {
            if(head->val > prev)
            {
                while(s1.size()>0 and s1.top() < head->val)
                {
                    s1.pop();
                }
                
            }
            s1.push(head->val);
            prev = head->val;
            head = head->next;
        }
        
        // reverse the stack
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        head = ans;
        while(!s2.empty())
        {   
            ans->next = new ListNode(s2.top());
            s2.pop();
            ans = ans->next;
        }
        
        return head->next;
    }
};