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
        vector<int> v;
        ListNode* tmp;
        tmp=head;
        while(tmp)
        {
            v.push_back(tmp->val);
            tmp=tmp->next;
        }
        int n=v.size(),i;
        for(i=0;i<n/2;i++)
        {
            if(v[i]!=v[n-i-1]) return false; 
        }
        return true;
    }
};