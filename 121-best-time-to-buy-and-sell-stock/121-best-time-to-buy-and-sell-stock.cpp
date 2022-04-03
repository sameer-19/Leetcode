class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a[100002]={0},mx=0,i,n=prices.size();
        for(i=n-1;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            a[i]=mx;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>prices[i]) ans=max(ans,a[i]-prices[i]);
        }
        return ans;
    }
};