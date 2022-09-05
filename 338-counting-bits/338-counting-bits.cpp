class Solution {
public:
    int count(int n)
    {
        int cnt=0;
        while(n)
        {
            cnt+=n%2;
            n/=2;
        }
        
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            ans[i]=count(i);
        }
        
        return ans;
    }
};