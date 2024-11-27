class Solution
{
    public:
        int bfs(vector<int> adj[], int n)
        {
            queue<int> q;
            q.push(0);
            int distance = 0;

            vector<bool> visited(n, false);
            visited[0] = true;

            while (!q.empty())
            {
                int size = q.size();

                for (int i = 0; i < size; i++)
                {
                    int node = q.front();
                    q.pop();
                    for (auto x: adj[node])
                    {
                        if (x == n - 1) return distance + 1;
                        if (!visited[x])
                        {
                            visited[x] = true;
                            q.push(x);
                        }
                    }
                }
                distance++;
            }

            return -1;
        }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector < int>> &queries)
    {
        vector<int> ans;

        vector<int> adj[n];

        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i + 1);
        }

        for (auto x: queries)
        {
            adj[x[0]].push_back(x[1]);
            ans.push_back(bfs(adj, n));
        }

        return ans;
    }
};