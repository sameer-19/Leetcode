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
    public:
        TreeNode* addOneRow(TreeNode *root, int val, int depth)
        {
            if (depth == 1)
            {
                TreeNode *node = new TreeNode(val);
                node->left = root;

                return node;
            }
            else
            {
                queue<TreeNode*> q;

                q.push(root);

                while (!q.empty())
                {
                    int sz = q.size();
                    depth--;
                    if (depth == 1) break;

                    for (int i = 0; i < sz; i++)
                    {
                        TreeNode *node = q.front();
                        q.pop();

                        if (node->left) q.push(node->left);
                        if (node->right) q.push(node->right);
                    }
                }

                while (!q.empty())
                {
                    TreeNode *node = q.front();
                    q.pop();

                    TreeNode *newNodeLeft = new TreeNode(val);
                    TreeNode *newNodeRight = new TreeNode(val);

                    if (node->left) newNodeLeft->left = node->left;
                    node->left = newNodeLeft;

                    if (node->right) newNodeRight->right = node->right;
                    node->right = newNodeRight;
                }

                return root;
            }
        }
};