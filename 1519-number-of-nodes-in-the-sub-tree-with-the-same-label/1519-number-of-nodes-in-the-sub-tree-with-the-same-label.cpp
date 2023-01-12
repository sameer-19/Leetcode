class Solution {
public:
    vector<int> ans;
    vector<int> solve(int idx,int n,vector<pair<int,char>> adj[],vector<bool> &visited,string &labels)
    {
        visited[idx] = true;
        vector<int> cnt(26,0);
        cnt[labels[idx]-'a']++;
        
        for(auto child: adj[idx])
        {
            if(visited[child.first]) continue;
            else
            {
                vector<int> count = solve(child.first,n,adj,visited,labels);
                for(int i=0;i<26;i++)
                {
                    cnt[i]+=count[i];
                }
            }
        }
        
        ans[idx] = cnt[labels[idx]-'a'];
        
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<pair<int,char>> adj[n];
        ans.resize(n+1);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],labels[edges[i][1]]});
            adj[edges[i][1]].push_back({edges[i][0],labels[edges[i][0]]});
        }
        
        
        vector<bool> visited(n,false);
        
        solve(0,n,adj,visited,labels);
        vector<int> res(n,1);
        for(int i=0;i<n;i++) res[i]=ans[i];
        
        return res;
    }
};