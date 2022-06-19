class Solution {
public:
    bool solve(vector<int> v,int mid,int h)
    {
        int i,ans=0;
        for(i=0;i<v.size();i++)
        {
            ans+=ceil((double)v[i]/mid);
        }
        if(ans<=h) return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=INT_MAX,i,ans=INT_MAX,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            bool z = solve(piles,mid,h);
            if(z)
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};