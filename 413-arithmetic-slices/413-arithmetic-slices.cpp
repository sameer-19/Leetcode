class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans=0,i,j,n=a.size();
        for(i=0;i<n-1;i++)
        {
            int d=a[i+1]-a[i];
            for(j=i+2;j<n;j++)
            {
                if(j-i>=2)
                {
                    if(a[j]-a[j-1]==d) ans++;
                    else break;
                }
                else if(a[j]-a[j-1]!=d) 
                {
                    break;
                }
            }
        }
        return ans;
    }
};