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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* tmp=head;
        
        while(tmp)
        {
            n++;
            tmp=tmp->next;
        }
        
        int carry=n%k;
        int width=n/k;
        
        vector<ListNode*> ans(k);
        
        tmp=head;
        
        for(int i=0;i<k;i++)
        {
            ListNode* root=new ListNode(0),*ptr=root;
            
            for(int j=0;j<width+(i<carry ? 1 : 0);j++)
            {
                ptr->next =new ListNode(tmp->val);
                ptr=ptr->next;
                if(tmp!=NULL) tmp=tmp->next;
            }
            ans[i]=root->next;
        }
        
        return ans;
    }
};