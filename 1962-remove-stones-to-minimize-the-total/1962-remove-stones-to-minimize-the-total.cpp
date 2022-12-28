class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n=piles.size();
        
        for(int i=0;i<n;i++) pq.push(piles[i]);
        
        while(k--)
        {
            int pile = pq.top();
            pq.pop();
            int remove = pile/2;
            pile-=remove;
            pq.push(pile);
        }
        
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};