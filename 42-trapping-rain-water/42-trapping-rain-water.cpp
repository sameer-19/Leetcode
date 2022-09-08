class Solution {
public:
    int bruteForce(vector<int> &height)
    {
        int i,j,n=height.size();
        
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            int lmax=height[i],rmax=height[i];
            j=i-1;
            while(j>=0)
            {
                lmax=max(lmax,height[j--]);
            }
            j=i+1;
            while(j<n)
            {
                rmax=max(rmax,height[j++]);    
            }
            int mn=min(lmax,rmax);
            ans+=mn-height[i];
        }
        
        return ans;
    }
    
    int optimal(vector<int> &height)
    {
        int n=height.size(),i,j,ans=0;
        int pre[n],suf[n];
        
        pre[0]=height[0];
        suf[n-1]=height[n-1];
        for(i=1;i<n;i++)
        {
            pre[i]=max(pre[i-1],height[i]);
        }
        for(i=n-2;i>=0;i--)
        {
            suf[i]=max(suf[i+1],height[i]);
        }
        
        for(i=0;i<n;i++)
        {
            ans+=min(pre[i],suf[i])-height[i];
        }
        
        return ans;
    }
    
    int trap(vector<int>& height) {
        
        return optimal(height);
        // return bruteForce(height);
    }
};