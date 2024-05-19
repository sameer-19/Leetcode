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
class Solution {
public:
    int getDistributeCoins(TreeNode* root, TreeNode* parent)
    {
        if(!root) return 0;
        
        int moves = getDistributeCoins(root->left,root) + getDistributeCoins(root->right,root); // number of moves needed by left and right child to distribute coins
        int value = root->val-1; // get coins for current node
        if(parent) parent->val+=value; // add the excess/less coins to parent node
        moves+=abs(value); // add the absolute number of moves required for current node
        
        return moves; // return left+right+current node moves
    }
    
    int distributeCoins(TreeNode* root) {
        return getDistributeCoins(root, nullptr);
    }
};