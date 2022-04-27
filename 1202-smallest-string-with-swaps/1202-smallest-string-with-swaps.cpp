class Solution {
public:
    void dfs(int idx,int n,bool visited[],vector<int> adj[],vector<int> &res)
    {
        visited[idx]=true;
        res.push_back(idx);
        for(auto x: adj[idx])
        {
            if(!visited[x])
            {
                dfs(x,n,visited,adj,res);
            }
        }
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // find all the connected components characters and take all characters and sort them in increasing order
        int i,j,n=s.length();
        
        vector<int> adj[100005];
        
        for(i=0;i<pairs.size();i++){
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        bool visited[100005]={false};
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                vector<int> v;
                dfs(i,n,visited,adj,v);
                vector<char> ct;
                for(auto x: v) ct.push_back(s[x]);
                sort(ct.begin(),ct.end());
                sort(v.begin(),v.end());
                j=0;
                while(j<v.size())
                {
                    s[v[j]]=ct[j];
                    j++;
                }
            }
        }
        return s;
        
    }
};