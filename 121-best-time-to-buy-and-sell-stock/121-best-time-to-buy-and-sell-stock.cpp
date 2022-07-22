class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],i,n=prices.size();
        
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            ans=max(ans,(prices[i]-mn));
            mn=min(mn,prices[i]);
        }
        
        return ans;
    }
};