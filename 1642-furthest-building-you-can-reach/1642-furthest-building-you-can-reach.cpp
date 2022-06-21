class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int i=0,n=h.size(),jump;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        while(i<n-1 and pq.size()<ladders)
        {
            jump=h[i+1]-h[i];
            if(jump>0) pq.push(jump);
            i++;
        }
        
        while(i<n-1)
        {
            jump=h[i+1]-h[i];
            
            if(jump>0)
            {
                if(pq.size()>0 and pq.top()<jump)
                {
                    bricks-=pq.top();
                    pq.pop();
                    pq.push(jump);
                }
                else bricks-=jump;
            }
            
            if(bricks<0) return i;
            
            i++;
        }
        
        return i;
    }
};