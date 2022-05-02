class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ans=1,n=nums.size(),cnt=0;
        
        vector<int> result(n),pref(n+2),suff(n+2);
        
        int i=0,j=n+1;
        pref[i++]=1; 
        suff[n-1]=1;
        
        for(i=1;i<n;i++) 
        {
            pref[i]=pref[i-1]*nums[i-1];
        }
        for(i=n-2;i>=0;i--) suff[i]=suff[i+1]*nums[i+1];
        
        for(i=0;i<n;i++)
        {
            if(i==0) result[i]=suff[i];
            else if(i==n-1) result[i]=pref[i];
            else
            {
                result[i]=pref[i]*suff[i];
            }
        }
        
        // for(auto x: suff) cout<<x<<" ";
        
        return result;
    }
};