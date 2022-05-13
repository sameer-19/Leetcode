/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* tmp=root;
        
        queue<Node*> q;
        q.push(tmp);
        
        while(!q.empty())
        {
            int sz=q.size();
            Node* prev;
            
            for(int i=0;i<sz;i++)
            {
                Node* z=q.front();
                q.pop();
                if(i!=0)
                {
                    prev->next=z;
                    prev=z;
                }
                else
                {
                    prev=z;
                }
                if(z->left) q.push(z->left);
                if(z->right) q.push(z->right);
            }   
        }
        return root;
    }
};