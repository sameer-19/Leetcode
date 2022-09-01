class Solution {
public:
    
    int bruteForce(vector<int>& h)
    {
        int ans=0,i,j,n=h.size();
        
        for(i=0;i<n;i++)
        {
            int lmax=h[i],rmax=h[i];
            for(j=i-1;j>=0;j--) lmax=max(lmax,h[j]);
            for(j=i+1;j<n;j++) rmax=max(rmax,h[j]);
            
            int mn=min(lmax,rmax);
            ans+=mn-h[i];
        }
        
        return ans;
    }
    
    int optimalSolution(vector<int> &h)
    {
        int i,n=h.size(),ans=0;
        
        vector<int> prefMax(n,0),suffMax(n,0);
        prefMax[0]=h[0];
        suffMax[n-1]=h[n-1];
        
        for(i=1;i<n;i++) prefMax[i]=max(prefMax[i-1],h[i]);
        for(i=n-2;i>=0;i--) suffMax[i]=max(suffMax[i+1],h[i]);
        
        for(i=0;i<n;i++)
        {
            ans+=(min(prefMax[i],suffMax[i]))-h[i];
        }
        
        return ans;
    }
    
    int optimal(vector<int> &h)
    {
        int n=h.size(),left,right;
        left=0;right=n-1;
        
        int ans=0,lmax=0,rmax=0;
        
        while(left<right)
        {
            if(h[left]<=h[right])
            {
                lmax=max(lmax,h[left]);
                ans+=lmax-h[left];
                left++;
            }
            else
            {
                rmax=max(rmax,h[right]);
                ans+=rmax-h[right];
                right--;
            }
        }
        
        return ans;
    }
    
    int trap(vector<int>& height) {
        // return bruteForce(height);
        // return optimalSolution(height);
        return optimal(height);
        
    }
};