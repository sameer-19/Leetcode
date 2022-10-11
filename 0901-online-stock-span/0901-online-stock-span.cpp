class StockSpanner {
public:
    // {price,ans} pair in stack stored
    stack<pair<int,int>> s;
    // stack stores all the elements in the decreasing order.
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty())
        {
            s.push({price,1});
            return 1;
        }
        int ans=1;
        
        while(!s.empty() and s.top().first<=price)
        {
            pair<int,int> p = s.top();
            s.pop();
            ans+=p.second;
        }
        
        s.push({price,ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */