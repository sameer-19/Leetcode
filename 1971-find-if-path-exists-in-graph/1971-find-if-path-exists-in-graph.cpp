class Solution
{
    public:
        bool solve(int source, vector<bool> &visited, map<int, vector< int>> &mp, int destination) {
            if(visited[source]) return false;
            
            visited[source] = true;
            
            for(auto node: mp[source])
            {
                if(node==destination) return true;
                if(solve(node, visited, mp, destination)) return true;
            }
            
            return false;
        }

    bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
    {
        if(n==1) return true;
        vector<bool> visited(n, false);
        map<int, vector < int>> mp;

        for (int i = 0; i < edges.size(); i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        return solve(source, visited, mp, destination);
    }
};