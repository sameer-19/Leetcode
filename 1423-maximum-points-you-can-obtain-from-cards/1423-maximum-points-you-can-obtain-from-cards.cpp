class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        
        int n=card.size(),i,ans=0;
        
        vector<int> pref(n,0),suff(n,0);
        
        pref[0]=card[0];
        suff[n-1]=card[n-1];
        
        for(i=1;i<n;i++) pref[i]=pref[i-1]+card[i];
        
        for(i=n-2;i>=0;i--) suff[i]=suff[i+1]+card[i];
        
        ans=max(ans,pref[k-1]);
        ans=max(ans,suff[n-k]);
        
        int c=n-k,sum;
        
        for(i=0;i<k;i++)
        {   
            sum=0;
            if(c+1<n) sum=pref[i]+suff[c+1],c++;
            else sum=pref[i];

            ans=max(ans,sum);
        }
        
        return ans;
    }
};