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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp=head;
        int n=0,cnt=0;
        while(tmp)
        {
            n++;
            tmp=tmp->next;
        }
        tmp=head;
        int element1=0,element2=0;
        while(tmp)
        {
            cnt++;
            if(cnt==k)
            {
                element1=tmp->val;
            }
            if(cnt==n-k+1){
                element2=tmp->val;
            }
            tmp=tmp->next;
        }
        tmp=head;cnt=0;
        while(tmp)
        {
            cnt++;
            if(cnt==k)
            {
                tmp->val=element2;
            }
            if(cnt==n-k+1){
                tmp->val=element1;
            }
            tmp=tmp->next;
        }
        return head;
    }
};