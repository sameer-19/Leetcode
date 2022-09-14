/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    unordered_map<int,int> mp;
    public:

    void solve(TreeNode* root,int &ans)
    {
        if(!root) return;
        
        mp[root->val]++;
        
        if(!root->left and !root->right)
        {
            int cnt=0;
            for(auto x: mp)
            {
                if(x.second%2) cnt++;
            }
            if(cnt<=1) 
                ans++;
        }
        
        solve(root->left,ans);
        solve(root->right,ans);
        
        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        // vector<int> res;
        int ans = 0,res=0;

        solve(root, ans);

        return ans;
    }
};