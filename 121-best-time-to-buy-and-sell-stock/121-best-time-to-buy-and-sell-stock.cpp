class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=-1,i,n=prices.size();
        
        int ans=0;
        
        for(i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                mx=prices[i];
            }
            else{
                ans=max(ans,(mx-prices[i]));
                mx=max(mx,prices[i]);
            }
        }
        
        return ans;
    }
};