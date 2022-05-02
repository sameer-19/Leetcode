class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        
        int i,n=a.size();
        
        vector<int> suff(n);
        
        int mx=-1;
        
        for(i=n-1;i>=0;i--)
        {
            suff[i]=mx;
            mx=max(mx,a[i]);
        }
        
        return suff;
    }
};