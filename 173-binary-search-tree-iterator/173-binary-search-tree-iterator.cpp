/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int cnt=0;
    
    void solve(TreeNode* root)
    {
        if(!root) return;
        
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        int d=v[cnt];
        cnt++;
        return d;
    }
    
    bool hasNext() {
        // cout<<cnt<<" ";
        if(cnt<v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */