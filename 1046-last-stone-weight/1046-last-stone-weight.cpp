class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        int i,n=stones.size();
        
        for(i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size()>1)
        {
            int p=pq.top();
            pq.pop();
            
            int q=pq.top();
            pq.pop();
            
            if(p!=q) pq.push(abs(p-q)); 
        }
        
        if(pq.size()>0) return pq.top();
        
        return 0;
    }
};