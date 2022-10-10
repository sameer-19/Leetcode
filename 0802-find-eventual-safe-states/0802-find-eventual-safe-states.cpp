class Solution {
public:
//     function for dfs algo finding cycle in graph
    bool dfs(int root,vector<int> adj[],vector<int> &visited,
                                        vector<int> &pathVisited,vector<int> &mark)
    {
        visited[root]=1;
        pathVisited[root]=1;
        
        for(auto node: adj[root])
        {
            if(!visited[node])
            {
                if(dfs(node,adj,visited,pathVisited,mark)) return true;
            }
            else if(pathVisited[node]) return true;
        }
        
        pathVisited[root] = 0;
        mark[root]=1;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> adj[n];
        
        // adjacency list formation
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        // stores the safe nodes.
        vector<int> ans,mark(n,0);
        
        vector<int> visited(n,0),pathVisited(n,0);
        // Applying DFS algo for cycle detection in directed graph
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,pathVisited,mark);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(mark[i]) ans.push_back(i);
        }
        
        return ans;
    }
};