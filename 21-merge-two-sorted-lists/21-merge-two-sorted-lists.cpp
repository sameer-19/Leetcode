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
    ListNode* solve(ListNode* ans,ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            ans->next=l2;
            return ans->next;
        }
        if(l2==NULL)
        {
            ans->next=l1;
            return ans->next;
        }
        if((l1->val)<=(l2->val))
        {
            ListNode* z=new ListNode(l1->val);
            ans->next=z;
            ans=ans->next;
            l1=l1->next;
            solve(ans,l1,l2);
        }
        else
        {
            ListNode* z=new ListNode(l2->val);
            ans->next=z;
            ans=ans->next;
            l2=l2->next;
            solve(ans,l1,l2);
        }
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode* tmp=ans;
        return solve(ans,l1,l2);
        // vector<int> v;
        // ListNode *tmp;
        // tmp=l1;
        // while(tmp!=NULL)
        // {
        //     v.push_back(tmp->val);
        //     tmp=tmp->next;
        // }
        // tmp=l2;
        // while(tmp!=NULL)
        // {
        //     v.push_back(tmp->val);
        //     tmp=tmp->next;
        // }
        // if(v.size()==0) return l1;
        // sort(v.begin(),v.end());
        // ListNode *ans=new ListNode(v[0]);
        // tmp=ans;
        // for(int i=1;i<size(v);i++)
        // {
        //     ListNode *z=new ListNode(v[i]);
        //     ans->next=z;
        //     ans=ans->next;
        // }
        // return tmp;
    }
};