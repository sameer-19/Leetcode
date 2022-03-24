class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        sort(a.begin(),a.end());
        int n=a.size(),i,j,ans=0;
        i=0;j=n-1;
        if(n==1) return 1;
        while(i<=j)
        {
            if(a[i]+a[j]>limit)
            {
                ans++;
                j--;
            }
            else 
            {
                ans++;
                i++;
                j--;
            }
        }
        
        return ans;
    }
};