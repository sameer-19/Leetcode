#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &visited,vector<int> &res)
    {
        if(visited[node]) return;
        
        visited[node]=true;
        res.push_back(node);
        
        for(auto child: adj[node])
        {
            if(!visited[child])
            {
                dfs(child,adj,visited,res);
            }
        }
        
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),i,j;
        
        vector<int> adj[n+1];
        
        for(i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                adj[i].push_back(edges[i]);
            }
        }
        
        vector<int> a,b;
        vector<bool> visited(n+1);
        
        for(i=0;i<n;i++) visited[i]=false;
        
        dfs(node1,adj,visited,a);
        
        for(i=0;i<n;i++) visited[i]=false;
        
        dfs(node2,adj,visited,b);
        
        map<int,int> mp1,mp2;
        
        for(i=0;i<a.size();i++)
        {
            mp1[a[i]]=i+1;
        }
        
        for(i=0;i<b.size();i++)
        {
            mp2[b[i]]=i+1;
        }
        
        int idx=-1,mx=INT_MAX;
        
        for(i=0;i<a.size();i++)
        {
            if(mp2[a[i]]>0)
            {
                int dist= max(mp1[a[i]],mp2[a[i]]);
                if(dist<mx)
                {
                    mx=dist;
                    idx=a[i];
                }
                else if(dist==mx)
                {
                    if(a[i]<idx)
                    {
                        idx=a[i];
                    }
                }
            }
        }
        
        return idx;
//         for(auto x : a) cout<<x<<" ";
//         cout<<endl;
        
//         for(auto x : b) cout<<x<<" ";
        
        return 0;
    }
};