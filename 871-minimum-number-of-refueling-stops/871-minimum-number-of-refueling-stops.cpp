class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size(),i,j;
        
        int prev=0,ans=0;
        
        priority_queue<int> pq;
        
        for(auto station: stations)
        {
            int location = station[0];
            int capacity = station[1];
            startFuel-= location-prev;
            
            while(!pq.empty() and startFuel<0)
            {
                startFuel+=pq.top();
                pq.pop();
                ans++;
            }
            
            if(startFuel<0) return -1;
            pq.push(capacity);
            prev=location;            
        }
        
        startFuel-= target-prev;
        while(!pq.empty() and startFuel<0)
        {
            startFuel+=pq.top();
            pq.pop();
            ans++;
        }

        if(startFuel<0) return -1;
        
        return ans;
    }
};