class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        
        vector<int> visited(10005,true);
        
        for(auto x: banned) visited[x] = false;
        
        int ans=0,sum=0;
        
        for(int i=1;i<=n;i++)
        {
            if(visited[i] and sum+i<=maxSum)
            {
                visited[i] = false;
                ans++;
                sum+=i;
            }
        }
        
        return ans;
    }
};