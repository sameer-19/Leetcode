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

class Solution
{
    public:
        vector<vector < int>> solve(Node *root)
        {
            vector<vector < int>> ans;

            queue<Node*> q;

            q.push(root);

            while (!q.empty())
            {
                int size = q.size();

                vector<int> result;

                for (int i = 0; i < size; i++)
                {
                    Node *node = q.front();
                    q.pop();
                    result.push_back(node->val);

                    for (auto child: node->children)
                    {
                        if (child)
                        {
                            q.push(child);
                        }
                    }
                }

                ans.push_back(result);
            }

            return ans;
        }

    vector<vector < int>> levelOrder(Node *root)
    {
        vector<vector < int>> ans;

        if (!root) return ans;

        return solve(root);
    }
};