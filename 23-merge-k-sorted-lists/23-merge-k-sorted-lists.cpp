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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=new ListNode(0);
        
        ListNode* result=ans;
        
        vector<int> res;
        
        int i,n=lists.size();
        
        for(i=0;i<n;i++)
        {
            ListNode* tmp=lists[i];
            while(tmp)
            {
                res.push_back(tmp->val);
                tmp=tmp->next;
            }
        }
        
        sort(res.begin(),res.end());
        
        i=0;
        n=res.size();
        
        while(i<n)
        {
            ListNode* p = new ListNode(res[i++]);
            ans->next=p;
            ans=ans->next;
        }
        
        return result->next;
    }
};