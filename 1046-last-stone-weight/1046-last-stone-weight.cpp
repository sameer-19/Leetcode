class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq;
        int i,j;
        for(i=0;i<v.size();i++)
        {
            pq.push(v[i]);
        }
        while(!pq.empty())
        {
            int x=pq.top(),y=-1;
            pq.pop();
            if(!pq.empty())
            {
                y=pq.top();
                pq.pop();
            }
            if(y==-1) return x;
            else 
            {
                if(x!=y) 
                {
                    x-=y;
                    pq.push(x);
                }
            }
        }
        return 0;
    }
};