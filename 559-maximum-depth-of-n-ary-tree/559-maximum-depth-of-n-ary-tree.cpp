/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int solve(int h,Node* root)
    {
        if(!root) return 0;
        
        int mx=h;
        
        for(auto child : root->children)
        {
            mx=max(mx,solve(h+1,child));
        }
        
        return mx;
    }
        
    
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        return solve(1,root);
    }
};