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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        
        vector<int> v;
        
        ListNode* list = head;
        
        while(list){ v.push_back(list->val); list=list->next; }
    
        for(int i=0;i<v.size()-1;i+=2)
        {
            swap(v[i],v[i+1]);
        }
        
        list=head;
        int c=0;
        while(list)
        {
            list->val = v[c++];
            list=list->next;
        }
        
        return head;
    }
};