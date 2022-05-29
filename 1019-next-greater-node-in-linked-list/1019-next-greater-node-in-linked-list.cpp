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
    vector<int> nextLargerNodes(ListNode* head) {
        int i,n=0;
        ListNode* tp=head;
        vector<int> v;
        
        while(tp) { n++; v.push_back(tp->val); tp=tp->next; }
        
        vector<int> ans(n);
        
        stack<int> s;
        
        ans[n-1]=0;
        
        s.push(v[n-1]);
        
        for(i=n-2;i>=0;i--)
        {
            while(!s.empty() and s.top()<=v[i]) s.pop();
            
            if(s.empty())
            {   
                ans[i]=0;
            }
            else 
            {
                ans[i]=s.top();
            }
            s.push(v[i]);
        }
        
        return ans;
    }
};