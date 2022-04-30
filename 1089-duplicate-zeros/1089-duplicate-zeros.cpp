class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        int n=a.size();
        
        vector<int> ans(n);
        
        int k=0,i=0;
        
        while(k<n)
        {
            if(a[i]==0)
            {
                ans[k]=a[i];
                k++;
                if(k<n) ans[k]=a[i];
                k++;
                i++;
            }
            else
            {
                ans[k]=a[i];
                i++;
                k++;
            }   
        }
        a=ans;
    }
};