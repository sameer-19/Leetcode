class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),i,j;
    
        int ans=INT_MAX;    
        
        long pref[n],suff[n];
        
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        
        for(i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];
        
        for(i=n-2;i>=0;i--) suff[i]=suff[i+1]+nums[i];
        
        for(i=0;i<n;i++)
        {
            if(pref[i]==x) 
            {
                ans=min(ans,i+1);
            }
            if(suff[i]==x) ans=min(ans,n-i);
        }
        
        reverse(suff,suff+n);
        
        for(i=0;i<n-1;i++)
        {
            int sum=x-pref[i];
            if(binary_search(suff,suff+n-i-1,sum)) 
            {
                // cout<<i;
                
                auto low=lower_bound(suff,suff+n,sum)-suff;
                
                int tp=i+1+low+1;
                ans=min(ans,tp);
            }
        }
        
        if(ans!=INT_MAX) return ans;
        
        return -1;
        // return (ans ? ans!=INT_MAX : -1);    
    }
};