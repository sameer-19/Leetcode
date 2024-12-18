class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();
        vector<int> ans(prices);
        
        for(int i=0;i<n;i++)
        {
            int j = i+1;   
            while(j<n and prices[j]>prices[i]) j++;
            
            if(j<n) ans[i] = prices[i]-prices[j];
        }
        
        return ans;
    }
};