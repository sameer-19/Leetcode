class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n=nums.size();
        
        vector<bool> visited(n, false);        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++) pq.push({nums[i], i});
        
        while(!pq.empty()) {
            int element = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            if(!visited[idx])
            {
                visited[idx] = true;
                if(idx-1>=0) visited[idx-1] = true;
                if(idx+1<n) visited[idx+1] = true;
                ans += element;
            }
        }
        
        return ans;
    }
};