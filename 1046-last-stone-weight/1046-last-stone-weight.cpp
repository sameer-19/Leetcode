class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &x: stones) pq.push(x);
        
        while(pq.size()>1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first==second) continue;
            else
            {
                if(first>second) pq.push(first-second);
                else pq.push(second-first);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};