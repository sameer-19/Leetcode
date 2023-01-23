class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> visited(n+1,0),prev(n+1,0);
        
        for(int i=0;i<trust.size();i++)
        {
            visited[trust[i][1]]++;
            prev[trust[i][0]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==n-1 and prev[i]==0) return i;
        }
        
        return -1;
    }
};