class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int threshold) {
        int count=0,i;
        
        double ans=0;
        int n=a.size(),sum=0;
        
        for(i=0;i<k;i++) sum+=a[i];
        ans=(double)sum/k;
        if(ans>=threshold) count++;
        
        for(i=k;i<n;i++)
        {
            sum+=a[i]-a[i-k];
            ans=(double)sum/k;
            if(ans>=threshold) count++;
        }
        
        return count;
    }
};