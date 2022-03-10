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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=new ListNode();
        ListNode* tmp=ans;
        while(l1 && l2)
        {
            int sum=l1->val+l2->val;
            sum+=carry;
            ListNode* z=new ListNode(sum%10);
            sum/=10;
            carry=sum;
            tmp->next=z;
            tmp=tmp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int sum=l1->val;
            sum+=carry;
            ListNode* z=new ListNode(sum%10);
            sum/=10;
            carry=sum;
            tmp->next=z;
            tmp=tmp->next;
            l1=l1->next;
        }
        while(l2)
        {
            int sum=l2->val;
            sum+=carry;
            ListNode* z=new ListNode(sum%10);
            sum/=10;
            carry=sum;
            tmp->next=z;
            tmp=tmp->next;
            l2=l2->next;
        }
        while(carry>0)
        {
            ListNode* z=new ListNode(carry%10);
            tmp->next=z;
            carry/=10;
        }
        return ans->next;
    }
};