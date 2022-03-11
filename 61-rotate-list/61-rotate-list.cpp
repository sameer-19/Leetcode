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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tmp=head;
        int n=0;
        int i=0;
        while(tmp)
        {
            n++;
            tmp=tmp->next;
        }
        k=k%n;
        vector<int> v(n);
        tmp=head;
        while(tmp)
        {
            v[(k+i)%n]=tmp->val;
            i++;
            tmp=tmp->next;
        }
        ListNode* ans=new ListNode(v[0]);
        tmp=ans;
        i=1;
        while(i<n)
        {
            ListNode* z=new ListNode(v[i]);
            i++;
            tmp->next=z;
            tmp=tmp->next;
        }
        return ans;
    }
};